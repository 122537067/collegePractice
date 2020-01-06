<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <%@ page import="com.test.UserInfoDao" %>
    
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
	<%
		//String btnSubmit = request.getParameter("submit");
		//if(btnSubmit==null) return;
		
		String username = request.getParameter("username");
		String pwd = request.getParameter("pwd");
		
		UserInfoDao dao = new UserInfoDao(request);
		
		
		if(!dao.login(username, pwd)){
			response.sendRedirect("login.jsp?error=1");
			return;
		}
		
		response.sendRedirect("test.jsp");
	%>
</body>
</html>