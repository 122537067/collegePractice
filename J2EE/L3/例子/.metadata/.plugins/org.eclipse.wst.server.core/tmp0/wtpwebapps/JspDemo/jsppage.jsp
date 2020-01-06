<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="java.text.SimpleDateFormat" %>
<%@ page import="java.util.Date" %>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>JSP页面的组成</title>
</head>
<body>
	<!-- 这是HTML注释(客户端可以看到源代码）-->
	<%-- 这是JSP注释 (客户端不可以看到源代码) --%>
	<%
		//使用预定格式将日期转换为字符串
		SimpleDateFormat formater = new SimpleDateFormat("yyyy年MM月dd日");
		String strCurrentTime = formater.format(new Date());
	%>
	当前时间：
	<%=strCurrentTime %>
</body>
</html>