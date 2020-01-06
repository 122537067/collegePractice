<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>用户登录</title>
</head>
<body>
	<h2 align="center">欢迎使用学生管理系统</h2>
	<hr/>
	<%
		request.setCharacterEncoding("utf-8");
		String err = request.getParameter("err");
		if(err!=null){
			String errmsg = "";
			if(err.equals("1")) errmsg = "用户不存在"; 
			out.print("<div style='text-align:center;color:red;'>"+errmsg+"</div>");
		}
	%>
	<form method="post" action="dologin.jsp">
	<table align="center">
		<tr>
			<td>用户名：</td>
			<td><input type="text" name="username"></td>
		</tr>
		<tr>
			<td>密码：</td>
			<td><input type="password" name="pwd"></td>
		</tr>
		<tr>
			<td colspan ="2" align="right"><input type="submit" value="确定"></td>
		</tr>
	</table>
	</form>
</body>
</html>