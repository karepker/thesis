"""Performs a 2 sample K-S test on pairs of segments."""


__author__ = "karepker@umich.edu Kar Epker"
__copyright__ = "Kar Epker, 2015"


import argparse
import itertools
import math
import matplotlib.pyplot
import numpy
import scipy.stats
import sys

from readable_directory import ReadableDirectory
from student_container_wrapper import StudentContainerWrapper
import vertex_analysis


if __name__ == '__main__':
    parser = argparse.ArgumentParser(
            description='Perform KS tests on all pairs of segments.')
    parser.add_argument(
            'weightedness', choices=['weighted', 'unweighted'],
            help='Either "weighted" or "unweighted".')
    parser.add_argument(
            'file', nargs='?', type=argparse.FileType('r'),
            default=sys.stdin, help='File to segment containing data to put in '
            'on which to run KS tests.')
    parser.add_argument(
            '-s', '--segmenter', default='all',
            choices=StudentContainerWrapper.SEGMENTERS.keys(),
            help='Segmenting function to use.')
    parser.add_argument(
            '--threshold', type=int, default=100,
            help='Filter segments with fewer than this many data points.')
    parser.add_argument(
            '--student-archive-path', dest='student_archive_path',
            help='Path of the student archive file.', required=True)
    parser.add_argument(
            '--swig-module-path', dest='swig_module_path',
            help='Directory containing the swig modules.',
            action=ReadableDirectory, required=True)

    args = parser.parse_args()

    # segment the data
    vertex_lines = vertex_analysis.get_id_values(args.file)
    students_wrapper = StudentContainerWrapper(
            args.swig_module_path, args.student_archive_path)
    segmenter = StudentContainerWrapper.SEGMENTERS[args.segmenter]
    mapped_lines = vertex_analysis.map_to_segments(
            vertex_lines, segmenter, students_wrapper)
    unfiltered_segments = vertex_analysis.reduce_to_segments(mapped_lines)

    # filter out small segments
    filtered_segments = {segment: values
                         for segment, values in unfiltered_segments.items()
                         if values.size >= args.threshold}
    segments = sorted(filtered_segments.keys())

    # put all the points from the distributions into a numpy array
    heatmatrix = numpy.zeros((len(segments), len(segments)))
    pvalue = numpy.zeros((len(segments), len(segments)))
    cells = {}
    for segment1, segment2 in itertools.combinations(filtered_segments, 2):
        ks_stat, p_val = scipy.stats.ks_2samp(
                filtered_segments[segment1], filtered_segments[segment2])
        segment1_index = segments.index(segment1)
        segment2_index = segments.index(segment2)

        pvalue[segment1_index, segment2_index] = p_val
        pvalue[segment2_index, segment1_index] = p_val

        # filter high p-values
        if p_val > 0.05:
            continue

        heatmatrix[segment1_index, segment2_index] = ks_stat
        heatmatrix[segment2_index, segment1_index] = ks_stat

        cells[(segment1, segment2)] = ks_stat


    # don't show the plot if there are too many segments. Instead, print out
    # KS values
    if len(segments) > 50:
        sorted_segments = sorted(
                [(segments[0], segments[1], ks_stat)
                 for segments, ks_stat in cells.items()],
                key=lambda x: x[2], reverse=True)
        for sorted_segment in sorted_segments:
            segment1 = sorted_segment[0]
            segment2 = sorted_segment[1]
            ks_stat = sorted_segment[2]

            segment1_index = segments.index(segment1)
            segment2_index = segments.index(segment2)

            print('{} || {} || {:2f} with p-value: {:2f}'.format(
                    segment1, segment2, ks_stat,
                    pvalue[segment1_index, segment2_index]))


    else:
        figsize = (3 + math.ceil(len(segments) * 0.6),
                   2 + math.ceil(len(segments) * 0.4))
        fig = matplotlib.pyplot.figure(figsize=figsize)
        ax = fig.add_subplot(1, 1, 1)
        heatmap = matplotlib.pyplot.pcolor(
                heatmatrix, cmap=matplotlib.pyplot.cm.Blues)
        heatmap.set_clim(vmin=0.0, vmax=1.0)

        # where the ticks are located
        ax.invert_yaxis()
        ax.xaxis.tick_top()

        # tick locations relative to the cell
        ax.set_xticks(numpy.arange(heatmatrix.shape[0]) + 0.5, minor=False)
        ax.set_yticks(numpy.arange(heatmatrix.shape[1]) + 0.5, minor=False)
        # stop a white bar from appearing due to rounding
        ax.set_xlim(right=len(segments))
        ax.set_ylim(bottom=len(segments))

        # tick labels
        ax.set_xticklabels(segments, minor=False)
        ax.set_yticklabels(segments, minor=False)
        matplotlib.pyplot.tick_params(
                axis='x', which='both', bottom='off', top='off')
        matplotlib.pyplot.tick_params(
                axis='y', which='both', right='off', left='off')

        colorbar = matplotlib.pyplot.colorbar(heatmap)
        colorbar.set_ticklabels([i for i in numpy.linspace(
                0, 1.0, 3 if len(segments) < 10 else 11)])
        colorbar.set_ticks([i for i in numpy.linspace(
                0, 1.0, 3 if len(segments) < 10 else 11)])

        # rotation of x-axis
        matplotlib.pyplot.xticks(rotation=90)

        # labels
        matplotlib.pyplot.xlabel(
                '{} degree distribution KS statistic between ...'.format(
                        args.weightedness.title()))
        ax.xaxis.set_label_position('top')
        matplotlib.pyplot.ylabel('and ...')


        # put the numbers in the boxes
        for y in range(heatmatrix.shape[0]):
            for x in range(heatmatrix.shape[1]):
                color = 'black' if abs(heatmatrix[y, x]) < 0.5 else 'white'
                text = ('%.2f' % heatmatrix[y, x] if pvalue[y, x] <= 0.05
                        else '-')
                matplotlib.pyplot.text(
                        x + 0.5, y + 0.5, text,
                        horizontalalignment='center',
                        verticalalignment='center',
                        color=color)

        fig.tight_layout()
        matplotlib.pyplot.show()
