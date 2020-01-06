package com.sms.service;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.sms.dao.IUserInfoDao;
import com.sms.iservice.IUserInfoService;
import com.sms.model.UserInfo;

@Service
public class UserInfoService implements IUserInfoService {
	
	@Autowired
	private IUserInfoDao userDao;

	@Override
	public List<UserInfo> getAllUsers() throws Exception {
		List<UserInfo> users = this.userDao.selectAllUser();
		return users;
	}

	@Override
	public UserInfo login(String username, String password) throws Exception {
		UserInfo user = this.userDao.selectUserByUsername(username);
		if(user==null) throw new Exception("用户不存在");
		
		if(!user.getPassword().equals(password)) throw new Exception("密码错误");
		
		
		return user;
	}

	@Override
	public void updatepwd(long userId, String newpwd) throws Exception {
		UserInfo user = this.userDao.selectUserById(userId);
		user.setPassword(newpwd);
		this.userDao.updateUser(user);
	}

}
