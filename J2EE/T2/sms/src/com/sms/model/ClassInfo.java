package com.sms.model;

public class ClassInfo
{
	private int ID;
	private String No; 
	private String Name;
	
	public int getID() {
		return ID;
	}
	public void setID(int iD) {
		ID = iD;
	}
	public String getNo() {
		return No;
	}
	public void setNo(String no) {
		No = no;
	}
	public String getName() {
		return Name;
	}
	public void setName(String name) {
		Name = name;
	}
	
	@Override
	public String toString() {
		return String.format("%d\t%s\t%s", this.ID,this.No,this.Name);
	}

}
