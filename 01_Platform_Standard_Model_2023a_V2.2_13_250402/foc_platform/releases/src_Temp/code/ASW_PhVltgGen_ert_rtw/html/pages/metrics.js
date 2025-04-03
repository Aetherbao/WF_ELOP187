function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.fcn["look2_iu8s16lu32n16tu16_binlcse"] = {file: "P:\\work\\01_Platform_Standard_Model_2023a_V2.2\\01_Platform_Standard_Model_2023a_V2.2_13_5\\foc_platform\\releases\\src_Temp\\code\\slprj\\ert\\_sharedutils\\look2_iu8s16lu32n16tu16_binlcse.c",
	stack: 39,
	stackTotal: 39};
	 this.metricsArray.fcn["mul_ssu32_loSR"] = {file: "P:\\work\\01_Platform_Standard_Model_2023a_V2.2\\01_Platform_Standard_Model_2023a_V2.2_13_5\\foc_platform\\releases\\src_Temp\\code\\slprj\\ert\\_sharedutils\\mul_ssu32_loSR.c",
	stack: 8,
	stackTotal: 8};
	 this.metricsArray.fcn["mul_wide_su32"] = {file: "P:\\work\\01_Platform_Standard_Model_2023a_V2.2\\01_Platform_Standard_Model_2023a_V2.2_13_5\\foc_platform\\releases\\src_Temp\\code\\slprj\\ert\\_sharedutils\\mul_wide_su32.c",
	stack: 28,
	stackTotal: 28};
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
	 this.codeMetricsSummary = '<a href="javascript:void(0)" onclick="return postParentWindowMessage({message:\'gotoReportPage\', pageName:\'ASW_PhVltgGen_metrics\'});">Global Memory: 0(bytes) Maximum Stack: 39(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
