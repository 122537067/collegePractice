package com.sms.web;

import javax.servlet.http.HttpServletRequest;

import org.apache.log4j.Logger;

import com.sms.model.UserInfo;

public class BaseController {
	protected Logger log = Logger.getLogger(this.getClass());
	
	protected UserInfo currentUser(HttpServletRequest request){
		UserInfo user = (UserInfo)request.getSession().getAttribute("user");
		return user;
	}
}
