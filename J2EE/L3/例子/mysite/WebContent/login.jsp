<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>用户登录</title>
</head>
<body>
	<h1 align="center">用户登录</h1>
	<hr>
	<%
		String error = request.getParameter("error");
		if(error!=null){
			if(error.equals("1"))
			{
				out.write("<font color='red'>用户不存在</font>");
			}
		}
	%>
	<form method="post" action="dologin.jsp">
		<table align="center">
			<tr>
				<td>用户名</td>
				<td><input type="text" id="username" name="username" ></input></td>
			</tr>
			<tr>
				<td>密码</td>
				<td><input type="password" id="pwd" name="pwd" ></input></td>
			</tr>
			<tr>
				<td colspan="2" align="right"><input type="submit" name="submit" value="确定"></td>
			</tr>
		</table>
	</form>
	


</body>
</html>