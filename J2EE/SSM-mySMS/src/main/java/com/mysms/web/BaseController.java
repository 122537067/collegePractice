package com.mysms.web;

import com.mysms.model.FunctionInfo;
import com.mysms.model.RoleInfo;
import com.mysms.model.UserInfo;
import org.apache.log4j.Logger;
import org.springframework.web.bind.annotation.ExceptionHandler;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

public class BaseController {
	protected Logger log = Logger.getLogger(this.getClass());
	
	protected UserInfo currentUser(HttpServletRequest request){
		UserInfo user = (UserInfo)request.getSession().getAttribute("user");
		return user;
	}

	protected void validPermission(HttpServletRequest request,String functionCode) throws Exception {
		UserInfo user = this.currentUser(request);
		if (user==null) throw new Exception("只有登录用户才可以访问");
		if (functionCode.equals("")) return;
		if (!hasThePermission(user,functionCode)) throw new Exception("无操作权限，请联系管理员");
	}

	public boolean hasThePermission(UserInfo user,String functionCode){
		for(RoleInfo role:user.getRoles()){
			for(FunctionInfo f:role.getFunctions()){
				if(f.getCode().equals(functionCode)) return true;
			}
		}

		return false;
	}

	public String exp(HttpServletResponse response, Exception e) throws IOException {
		PrintWriter out = response.getWriter();
		out.print("<script>" +
				"window.top.showError('"+e.getMessage()+"');" +
				"closeWindow();" +
				"</script>");
		return "err";
	}


	//@ExceptionHandler
	//public void exp(HttpServletRequest request, HttpServletResponse response, Exception ex) throws IOException {
    //
	//	request.setAttribute("ex",ex);
    //
	//	PrintWriter out = response.getWriter();
    //
	//	String errMsg = ex.getMessage();
    //
	//	out.print("<script>window.top.showError('"+errMsg+"');</script>");
    //
	//	//if(!request.getContextPath().contains("/delete")){
	//		out.print("<script>closeWindow();</script>");
	//	//}
    //
	//}
}
