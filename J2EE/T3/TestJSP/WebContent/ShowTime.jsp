<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"
    import="java.util.* , java.text.*"
    %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Show Time</title>
</head>
<body>
	Hello,now:
	<%
		SimpleDateFormat formater = new SimpleDateFormat("yyyy-mm-dd");
		String strCurrentTime = formater.format(new Date());
	%>
	
	<%=strCurrentTime %>
</body>
</html>