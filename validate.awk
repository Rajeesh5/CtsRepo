#!/bin/awk -f
BEGIN {			# Begin section
	 lineLen=0;


}  
	#User Define Function# 
function errorLog(errLine){
	printf("Error");
}



{
	lineLen=length($0);
	#if(lineLen>267)
	#	errorLog(NR);
	
	if(NR==1) 		#Header validation  HDR 20160614 19550500 0000019 OH 
	{
		HdrDef		= substr($0,1,3) ;
		ProcDt		= substr($0,4,8) ;										#(CCYYMMDD)
		ProcTm 		= substr($0,12,8) ;									#(HHMMSSMM)
		RecTotl		= substr($0,20,7) ;
		SrcSys 		= substr($0,27,2) ;
		SPACES		= substr($0,29,238) ;
		EndOfHrdInd	= substr($0,267,1) ;
		
		if(lineLen==267 && EndOfHrdInd)
		
		printf("%s %s %s %s %s %s %s", HdrDef,ProcDt,ProcTm,RecTotl,SrcSys,SPACES,EndOfHrdInd);

		
		
		
		
		
	}
	else
	{
		
	}
	

}       

 
END{}     # End section
