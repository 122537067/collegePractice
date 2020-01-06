<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>错误信息</title>
</head>
<%
	String errmsg = session.getAttribute("errmsg").toString();
%>
<body>

	<h2 align="center">奥，发生错误了：</h2>
	<hr>
	
	<div style="text-align:center;color:red;font-size:28px;">
		<%=errmsg %>
	</div>
</body>
</html>