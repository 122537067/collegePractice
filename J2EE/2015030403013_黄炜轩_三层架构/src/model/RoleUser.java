package model;

public class RoleUser {
	
	private long id;
	
	private long roleInfoId;
	
	private long userInfoId;

	public long getId() {
		return id;
	}

	public void setId(long id) {
		this.id = id;
	}

	public long getRoleInfoId() {
		return roleInfoId;
	}

	public void setRoleInfoId(long roleInfoId) {
		this.roleInfoId = roleInfoId;
	}

	public long getUserInfoId() {
		return userInfoId;
	}

	public void setUserInfoId(long userInfoId) {
		this.userInfoId = userInfoId;
	}

}
