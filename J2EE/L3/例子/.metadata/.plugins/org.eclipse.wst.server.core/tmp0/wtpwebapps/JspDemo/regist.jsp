<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>学生注册</title>
</head>
<body>
	<div style="text-align:center">
		<h4>请输入注册信息</h4>
		<form method="post" action="checkregist.jsp">
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
				<td>获悉渠道：</td>
				<td>
					<input type="checkbox" name="channel" value="报刊">报刊
					<input type="checkbox" name="channel" value="网路">网路
					<input type="checkbox" name="channel" value="朋友推荐">朋友推荐
					<input type="checkbox" name="channel" value="电视">电视
				</td>
			</tr>
			<tr>
				<td colspace="2">
					<input type="submit" value="确定">
				</td>
			</tr>
		</table>
		</form>
	</div>
</body>
</html>