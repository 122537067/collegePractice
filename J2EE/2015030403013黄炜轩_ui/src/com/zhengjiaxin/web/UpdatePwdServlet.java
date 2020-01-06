package com.zhengjiaxin.web;


import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.zhengjiaxin.model.UserInfo;
import com.zhengjiaxin.service.UserInfoService;

/**
 * 修改密码
 * @author hp
 *
 */
@WebServlet("/updatePassword.do")
public class UpdatePwdServlet extends HttpServlet {

	private static final long serialVersionUID = 1L;

	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		response.setCharacterEncoding("utf-8");
		
		String pwd = request.getParameter("newPassword");
		

		try{
			UserInfo user = (UserInfo)request.getSession().getAttribute("user");
			user.setPassword(pwd);
			
			new UserInfoService().updatePwd(user);
		
			response.getWriter().print("修改密码成功");
		}
		catch(Exception ex){
			ex.printStackTrace();
			response.getWriter().print(ex.getMessage());
		}
	}


}
