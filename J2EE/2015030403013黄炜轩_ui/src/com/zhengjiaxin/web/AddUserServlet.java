package com.zhengjiaxin.web;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.json.JSONObject;

import com.zhengjiaxin.model.ReturnData;
import com.zhengjiaxin.model.UserInfo;
import com.zhengjiaxin.service.UserInfoService;
/**
 * 添加用户信息
 * @author hp
 *
 */
@WebServlet("/adduser.do")
public class AddUserServlet extends HttpServlet {

	private static final long serialVersionUID = 1L;

	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		response.setCharacterEncoding("utf-8");
		
		String Username = request.getParameter("Username");
		String Password = request.getParameter("Password");
		
		ReturnData rd = new ReturnData();

		try{
			UserInfo user =  new UserInfo();
			user.setUsername(Username);
			user.setPassword(Password);
			
			new UserInfoService().addUserInfo(user);
		
			rd.setSuccess(true);
			rd.setMessage("添加用户成功");
		}
		catch(Exception ex){
			ex.printStackTrace();
			rd.setSuccess(false);
			rd.setMessage(ex.getMessage());
		}
		
		JSONObject json = new JSONObject(rd);

		response.getWriter().print(json);
	}


}
