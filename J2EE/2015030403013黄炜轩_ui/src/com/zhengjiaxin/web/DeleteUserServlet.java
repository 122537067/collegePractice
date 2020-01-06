package com.zhengjiaxin.web;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.json.JSONObject;

import com.zhengjiaxin.model.ReturnData;
import com.zhengjiaxin.service.UserInfoService;

/**
 * 删除用户信息
 * @author hp
 *
 */
@WebServlet("/userinfo/delete.do")
public class DeleteUserServlet extends HttpServlet {

	private static final long serialVersionUID = 1L;

	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		response.setCharacterEncoding("utf-8");
		
		long id = Long.parseLong(request.getParameter("id"));

		ReturnData rd = new ReturnData();

		try{
			new UserInfoService().deleteUserInfo(id);
		
			rd.setSuccess(true);
			rd.setMessage("删除用户成功");
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
