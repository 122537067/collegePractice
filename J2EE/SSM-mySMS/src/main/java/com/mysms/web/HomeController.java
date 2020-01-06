package com.mysms.web;


import com.mysms.iservice.IUserInfoService;
import com.mysms.model.UserInfo;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

import javax.servlet.http.HttpServletRequest;

@Controller
public class HomeController extends BaseController {
	
	@Autowired
	private IUserInfoService userInfoService;
	
	@RequestMapping(value="/login",method=RequestMethod.GET)
	public String login() throws Exception{
		log.debug("正在请求login");
		
		return "login";
	}
	
	@RequestMapping(value="/index",method=RequestMethod.GET)
	public String index() throws Exception{
		return "index";
	}
	
	
	@RequestMapping(value="/login",method=RequestMethod.POST)
	@ResponseBody
	public String login(HttpServletRequest request) throws Exception{
		String username = request.getParameter("username");
		String pwd = request.getParameter("pwd");
		
		try{
			UserInfo user = this.userInfoService.login(username,pwd);
			request.getSession().setAttribute("user", user);
			return "success";
		}
		catch(Exception ex){
			return ex.getMessage();
		}
	}
	
	@RequestMapping(value="/logout",method=RequestMethod.GET)
	public String logout(HttpServletRequest request){
		request.getSession().invalidate();
		return "login";
	}
	
	@RequestMapping(value="/updatePassword",method=RequestMethod.POST)
	@ResponseBody
	public String updatePassword(HttpServletRequest request) throws Exception{
		String newpwd = request.getParameter("newPassword");

		try{
			this.userInfoService.updatepwd(this.currentUser(request).getId(),newpwd);
			return "修改成功";
		}
		catch(Exception ex){
			log.error(ex.getMessage(),ex);
			return ex.getMessage();
		}
	}

}
