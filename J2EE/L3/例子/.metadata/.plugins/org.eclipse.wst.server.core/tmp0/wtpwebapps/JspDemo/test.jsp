<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="java.util.Date"  %>
<%@ page import="java.text.SimpleDateFormat"  %>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>我的网页</title>
</head>
<body>
	<h1>我的网页</h1>
	<hr/>
	<!-- 静态页面的注释  -->
	<%-- 服务器端的注释 --%>
	<%
		SimpleDateFormat format = new SimpleDateFormat("yyyy年MM月dd日 hh点mm分ss秒");
		String currentTime = format.format(new Date());
	%>
	<%=currentTime %>
	<hr/>
	<form method="post" action="test.jsp">
		名称：<input type="text" id="name" name="name"></input><br>
		<input type="submit" id="btnSubmit" name="btnSubmit" value="提交"></input>
	</form>
	<hr/>
	<%
		request.setCharacterEncoding("utf-8");
		String btnSubmit = request.getParameter("btnSubmit");
		String name = request.getParameter("name");
		System.out.println("btnSubmit="+btnSubmit);
		System.out.println("name="+name);
		
		if(btnSubmit==null) return;
		
		out.print("<h1>你输入的名称是："+name+"</h1>");
	%>
</body>
</html>