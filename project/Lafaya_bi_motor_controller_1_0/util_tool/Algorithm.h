#ifndef ALGORITHM_H_
#define ALGORITHM_H_

typedef union
{
	unsigned long parameter;
	struct
	{
		unsigned parameter1 : 4;
		unsigned parameter2 : 4;
		unsigned parameter3 : 4;
		unsigned parameter4 : 4;
		unsigned parameter5 : 4;
		unsigned parameter6 : 4;
		unsigned parameter7 : 4;
		unsigned parameter8 : 4;
	};
	struct
	{
		unsigned parameter2_1 : 8;
		unsigned parameter4_3 : 8;
		unsigned parameter6_5 : 8;
		unsigned parameter8_7 : 8;
	};
}PARAMETER_STYLE;



#endif

