package model;

public class RoleFunctionPermission {
	
	private long id;
	
	private long roleInfoId;
	
	private long functionInfoId;

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

	public long getFunctionInfoId() {
		return functionInfoId;
	}

	public void setFunctionInfoId(long functionInfoId) {
		this.functionInfoId = functionInfoId;
	}

}
