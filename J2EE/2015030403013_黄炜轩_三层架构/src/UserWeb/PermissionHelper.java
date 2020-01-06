package UserWeb;

import java.io.IOException;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import model.UserInfo;

public class PermissionHelper {
	
	public static final String user_session_key = "==login-user==";
	
	public static boolean validPermission(HttpServletRequest request, HttpServletResponse response,String functionCode){
		
		Object user = request.getSession().getAttribute(user_session_key);
		if(user==null){
			request.getSession().setAttribute("errmsg", "只有登录用户才可以访问奥");
			sendErrorPage(response);
			return false;
		}
		
		if(((UserInfo)user).hasThePermission(functionCode)) return true;
		
		request.getSession().setAttribute("errmsg", "该用户没有权限");
		sendErrorPage(response);
		
		return false;
	}
	
	private static void sendErrorPage(HttpServletResponse response){
		try {
			response.sendRedirect("error.jsp");
			return;
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
