#ifndef TEST_DATA_STREAMS_H
#define TEST_DATA_STREAMS_H

#include <string>

/* Enrollment tab in an easier to read format:
ID	SUBJECT	CATALOGNBR	COURSE_CODE	GRADE	GPAO	CUM_GPA	TOTALCREDITS	TOTALGRADEPTS	COURSECREDIT	TERM
312995	ENGLISH	125	NA	3.7	3.65909090909091	3.66538461538462	26	95.3	4	201403
312995	CHEM	210	CHEM_III	3.3	3.73181818181818	3.66538461538462	26	95.3	4	201403
312995	CHEM	211	CHEM_III_LAB	3	3.692	3.66538461538462	26	95.3	1	201407
312995	AAPTIS	277	NA	4	3.60454545454545	3.66538461538462	26	95.3	4	201403
500928	ENGLISH	125	NA	4	3.57538461538462	3.58181818181818	66	236.4	4	201403
500928	CHEM	210	CHEM_III	3.3	3.73181818181818	3.66538461538462	26	95.3	4	201403
147195	ENGLISH	125	NA	4	3.57538461538462	3.58181818181818	66	236.4	4	201403
147195	ENVIRON	311	NA	4	3.55483870967742	3.58181818181818	66	236.4	4	201405
147195	AAPTIS	277	NA	4	3.60454545454545	3.66538461538462	26	95.3	4	201403
352468	ENGLISH	125	NA	4	3.57538461538462	3.58181818181818	66	236.4	4	201403
352468	ENVIRON	311	NA	4	3.55483870967742	3.58181818181818	66	236.4	4	201405
352468	MATH	425	NA	4	4	4	27	108	3	201407
567890	MATH	425	NA	4	4	4	27	108.5	3	201407
*/

const std::string enrollment_tab{
"ID\tSUBJECT\tCATALOGNBR\tCOURSE_CODE\tGRADE\tGPAO\tCUM_GPA\tTOTALCREDITS\t"
"TOTALGRADEPTS\tCOURSECREDIT\tTERM\n"
"312995\tENGLISH\t125\tNA\t3.7\t3.65909090909091\t3.66538461538462\t26\t95.3\t"
"4\t201403\n"
"312995\tCHEM\t210\tCHEM_III\t3.3\t3.73181818181818\t3.66538461538462\t26\t95.3"
"\t4\t201403\n"
"312995\tCHEM\t211\tCHEM_III_LAB\t3\t3.692\t3.66538461538462\t26\t95.3\t1"
"\t201407\n"
"312995\tAAPTIS\t277\tNA\t4\t3.60454545454545\t3.66538461538462\t26\t95.3\t4\t"
"201403\n"
"500928\tENGLISH\t125\tNA\t4\t3.57538461538462\t3.58181818181818\t66\t236.4\t4"
"\t201403\n"
"500928\tCHEM\t210\tCHEM_III\t3.3\t3.73181818181818\t3.66538461538462\t26\t95.3"
"\t4\t201403\n"
"147195\tENGLISH\t125\tNA\t4\t3.57538461538462\t3.58181818181818\t66\t236.4\t4"
"\t201403\n"
"147195\tENVIRON\t311\tNA\t4\t3.55483870967742\t3.58181818181818\t66\t236.4\t4"
"\t201405\n"
"147195\tAAPTIS\t277\tNA\t4\t3.60454545454545\t3.66538461538462\t26\t95.3\t4\t"
"201403\n"
"352468\tENGLISH\t125\tNA\t4\t3.57538461538462\t3.58181818181818\t66\t236.4\t4"
"\t201403\n"
"352468\tENVIRON\t311\tNA\t4\t3.55483870967742\t3.58181818181818\t66\t236.4\t4"
"\t201405\n"
"352468\tMATH\t425\tNA\t4\t4\t4\t27\t108\t3\t201407\n"
"567890\tMATH\t425\tNA\t4\t4\t4\t27\t108.5\t3\t201407\n"
};

/* Student tab in an easier to read format
ID	GENDER	ETHNICITY	FIRST_TERM	DEGREE_TERM	TRANSFER	MAJOR1	MAJOR2	MAJOR1_LONG	MAJOR2_LONG	FIRST_DECLARE	FIRST_DECLARE_LONG	FIRST_DECLARE_TERM	PELL_STATUS	ACT_ENGL	ACT_MATH	ACT_COMP	COA
147195	M	2	200607	201003	N	9.0101	42.2704	Communication Studies/Speech C	Experimental Psychology	NA	NA	NA	N	NA	NA	NA	ULSA
312995	F	3	200807	201205	N	42.2706	NA	Physiological Psychology/Psych	NA	42.2706	Physiological Psychology/Psych	201103	N	24	25	24	ULSA
352468	F	1	201207	201303	N	NA	NA	NA	NA	NA	NA	NA	N	36	36	35	NA
500928	F	6	200707	201103	N	16.0905	45.0201	Spanish Language and Literatur	Anthropology	16.0905	Spanish Language and Literatur	200807	N	NA	NA	NA	ULSA
567890	M	6	200707	201103	N	16.0905	45.0201	Spanish Language and Literatur	Anthropology	16.0905	Spanish Language and		Literatur	200807	N	NA	NA	NA	ULSA
*/
const std::string student_tab{
"ID\tGENDER\tETHNICITY\tFIRST_TERM\tDEGREE_TERM\tTRANSFER\tMAJOR1\tMAJOR2\t"
"MAJOR1_LONG\tMAJOR2_LONG\tFIRST_DECLARE\tFIRST_DECLARE_LONG\t"
"FIRST_DECLARE_TERM\tPELL_STATUS\tACT_ENGL\tACT_MATH\tACT_COMP\tCOA\n"
"147195\tM\t2\t200607\t201003\tN\t9.0101\t42.2704\t"
"Communication Studies/Speech C\tExperimental Psychology\tNA\tNA\tNA\tN\tNA\tNA"
"\tNA\tULSA\n"
"312995\tF\t3\t200807\t201205\tN\t42.2706\tNA\tPhysiological Psychology/Psych\tNA\t"
"42.2706\tPhysiological Psychology/Psych\t201103\tN\t24\t25\t24\tULSA\n"
"352468\tF\t1\t201207\t201303\tN\tNA\tNA\tNA\tNA\tNA\tNA\tNA\tN\t36\t36\t35\t"
"NA\n"
"500928\tF\t6\t200707\t201103\tN\t16.0905\t45.0201\t"
"Spanish Language and Literatur\tAnthropology\t16.0905\tSpanish Language and "
"Literatur\t200807\tN\tNA\tNA\tNA\tULSA\n"
"567890\tM\t6\t200707\t201103\tN\t16.0905\t45.0201\t"
"Spanish Language and Literatur\tAnthropology\t16.0905\tSpanish Language and "
"Literatur\t200807\tN\tNA\tNA\tNA\tULSA\n"
};


#endif  // TEST_DATA_STREAMS_H
