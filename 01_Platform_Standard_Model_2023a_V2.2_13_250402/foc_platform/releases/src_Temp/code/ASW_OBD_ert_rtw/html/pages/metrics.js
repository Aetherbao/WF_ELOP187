function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.fcn["div_nzp_repeat_u32"] = {file: "P:\\work\\01_Platform_Standard_Model_2023a_V2.2\\01_Platform_Standard_Model_2023a_V2.2_13_5\\foc_platform\\releases\\src_Temp\\code\\slprj\\ert\\_sharedutils\\div_nzp_repeat_u32.c",
	stack: 13,
	stackTotal: 13};
	 this.metricsArray.fcn["look1_is16lu32n32ys16n_eAC3J1UD"] = {file: "P:\\work\\01_Platform_Standard_Model_2023a_V2.2\\01_Platform_Standard_Model_2023a_V2.2_13_5\\foc_platform\\releases\\src_Temp\\code\\slprj\\ert\\_sharedutils\\look1_is16lu32n32ys16n_eAC3J1UD.c",
	stack: 18,
	stackTotal: 18};
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
	 this.codeMetricsSummary = '<a href="javascript:void(0)" onclick="return postParentWindowMessage({message:\'gotoReportPage\', pageName:\'ASW_OBD_metrics\'});">Global Memory: 0(bytes) Maximum Stack: 28(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
