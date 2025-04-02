function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.fcn["look1_iu16lu32n16tu8_binlcse"] = {file: "P:\\work\\01_Platform_Standard_Model_2023a_V2.2\\01_Platform_Standard_Model_2023a_V2.2_13_5\\foc_platform\\releases\\src_Temp\\code\\slprj\\ert\\_sharedutils\\look1_iu16lu32n16tu8_binlcse.c",
	stack: 17,
	stackTotal: 17};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data; }; 
	 this.codeMetricsSummary = '<a href="javascript:void(0)" onclick="return postParentWindowMessage({message:\'gotoReportPage\', pageName:\'ASW_SigIn_metrics\'});">Global Memory: 0(bytes) Maximum Stack: 17(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
