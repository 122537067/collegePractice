package com.mysms.service;

import com.mysms.dao.IRoleInfoDao;
import com.mysms.dao.IUserInfoDao;
import com.mysms.iservice.IUserInfoService;
import com.mysms.model.RoleInfo;
import com.mysms.model.UserInfo;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class UserInfoService implements IUserInfoService {
	
	@Autowired
	private IUserInfoDao userDao;

	@Override
	public List<UserInfo> getAllUsers() throws Exception {
		return this.userDao.selectAllUser();
	}

	@Autowired
	private IRoleInfoDao roleInfoDao;

	@Override
	public UserInfo login(String username, String password) throws Exception {
		UserInfo user = this.userDao.selectUserByUsername(username);
		if(user==null) throw new Exception("用户不存在");
		
		if(!user.getPassword().equals(password)) throw new Exception("密码错误");
		
		user.setRoles(userDao.loadPermissions(user.getId()));
		for(RoleInfo roleInfo:user.getRoles()){
			roleInfo.setFunctions(this.roleInfoDao.getFunctions(roleInfo.getId()));
		}
		return user;
	}

	@Override
	public void insertUser(UserInfo user) throws Exception {
		int i = this.userDao.insertUser(user);
		if(i==0) throw new Exception("增加失败");
	}

	@Override
	public void deleteUser(int id) throws Exception {
		int i = this.userDao.deleteUser(id);
		if(i==0) throw new Exception("删除失败");
	}

	@Override
	public void updateUser(UserInfo user) throws Exception {
		int i = this.userDao.updateUser(user);
		if(i==0) throw new Exception("修改失败");
	}

	@Override
	public void updatepwd(int userId, String newpwd) throws Exception {
		UserInfo user = this.userDao.selectUserById(userId);
		user.setPassword(newpwd);
		this.userDao.updateUser(user);
	}

	@Override
	public UserInfo getUserById(int id) throws Exception {
		return this.userDao.selectUserById(id);
	}

	@Override
	public UserInfo getUserByUsername(String username) throws Exception {
		return this.userDao.selectUserByUsername(username);
	}

}
