<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="java.util.Date" %>
<%@ page import="java.text.SimpleDateFormat" %>

<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>JSP测试</title>
</head>
<body>
	<!-- 静态网页注释 -->
	<%-- 服务器端注释 --%>
	
	<%
		Date date = new Date();
		SimpleDateFormat sf = new SimpleDateFormat("yyyy年MM月dd日 HH点mm分ss秒");
		String currentDate = sf.format(date);
	%>
	<h1><%=currentDate %></h1>
</body>
</html>