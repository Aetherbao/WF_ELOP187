function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.fcn["div_nde_s32_floor"] = {file: "P:\\work\\01_Platform_Standard_Model_2023a_V2.2\\01_Platform_Standard_Model_2023a_V2.2_13_5\\foc_platform\\releases\\src_Temp\\code\\slprj\\ert\\_sharedutils\\div_nde_s32_floor.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["look1_iu16lu32n16ts16D_2s4GBl96"] = {file: "P:\\work\\01_Platform_Standard_Model_2023a_V2.2\\01_Platform_Standard_Model_2023a_V2.2_13_5\\foc_platform\\releases\\src_Temp\\code\\slprj\\ert\\_sharedutils\\look1_iu16lu32n16ts16D_2s4GBl96.c",
	stack: 16,
	stackTotal: 16};
	 this.metricsArray.fcn["look1_iu8lu32n16ts16Ds32_binlcs"] = {file: "P:\\work\\01_Platform_Standard_Model_2023a_V2.2\\01_Platform_Standard_Model_2023a_V2.2_13_5\\foc_platform\\releases\\src_Temp\\code\\slprj\\ert\\_sharedutils\\look1_iu8lu32n16ts16Ds32_binlcs.c",
	stack: 15,
	stackTotal: 15};
	 this.metricsArray.fcn["look2_is16lu32n16tu16_binlcse"] = {file: "P:\\work\\01_Platform_Standard_Model_2023a_V2.2\\01_Platform_Standard_Model_2023a_V2.2_13_5\\foc_platform\\releases\\src_Temp\\code\\slprj\\ert\\_sharedutils\\look2_is16lu32n16tu16_binlcse.c",
	stack: 38,
	stackTotal: 38};
	 this.metricsArray.fcn["mul_ssu32_hiSR"] = {file: "P:\\work\\01_Platform_Standard_Model_2023a_V2.2\\01_Platform_Standard_Model_2023a_V2.2_13_5\\foc_platform\\releases\\src_Temp\\code\\slprj\\ert\\_sharedutils\\mul_ssu32_hiSR.c",
	stack: 8,
	stackTotal: 8};
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
	 this.codeMetricsSummary = '<a href="javascript:void(0)" onclick="return postParentWindowMessage({message:\'gotoReportPage\', pageName:\'ASW_AST_metrics\'});">Global Memory: 0(bytes) Maximum Stack: 38(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
