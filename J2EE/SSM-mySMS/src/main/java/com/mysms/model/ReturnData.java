package com.mysms.model;

public class ReturnData {
	
	private boolean success;
	private String message;
	
	public ReturnData(){
		
	}
	
	public ReturnData(boolean success,String message){
		this.success = success;
		this.message = message;
	}
	
	
	public boolean getSuccess() {
		return success;
	}
	public void setSuccess(boolean success) {
		this.success = success;
	}
	public String getMessage() {
		return message;
	}
	public void setMessage(String message) {
		this.message = message;
	}
	
	

}
