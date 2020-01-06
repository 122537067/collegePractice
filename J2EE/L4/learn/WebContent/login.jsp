<%@ page language="java" import="java.util.*" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
</head>

<body> 
	<h2 align="center">欢迎使用</h2>
    	<form name=loginForm action="userlogin" method="post">    	
        <table align="center">
        	<tr>
        	<td>
        		<%
					request.setCharacterEncoding("utf-8");
					String err = request.getParameter("err");
					if(err!=null){
						String errmsg = "";
						if(err.equals("1")) errmsg = "用户不存在"; 
						out.print("<div style='text-align:center;color:red;'>"+errmsg+"</div>");
						}
				%>
        	</td>
        	</tr>
            <tr>
                <td>用户名：</td><td><input type=text name=username /></td>
            </tr>    
            <tr>
                <td>密码：</td><td><input type=password name=pwd /></td>
            <tr/>            
            <tr>
            <td colspan="2" align="center">
                <input type="submit" value="登录" />
            </td>
            </tr>  
		</table>   
		</form>
</body>
</html>