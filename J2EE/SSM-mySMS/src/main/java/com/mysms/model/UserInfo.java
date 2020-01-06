package com.mysms.model;

import java.util.List;

public class UserInfo {
	
	private int id;
	private String username;
	private String password;
	private List<RoleInfo> roles;
	
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getUsername() {
		return username;
	}
	public void setUsername(String username) {
		this.username = username;
	}
	public String getPassword() {
		return password;
	}
	public void setPassword(String password) {
		this.password = password;
	}
	public List<RoleInfo> getRoles() {
		return roles;
	}
	public void setRoles(List<RoleInfo> roles) {
		this.roles = roles;
	}

	@Override
	public String toString() {
		return "username="+this.username+",password="+this.password;
	}


}
