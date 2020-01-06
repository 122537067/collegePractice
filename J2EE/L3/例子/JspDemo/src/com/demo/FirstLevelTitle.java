package com.demo;

import java.util.Date;

public class FirstLevelTitle {
	
	private long id;
	
	private String titleName;
	
	private String creator;
	
	private Date createTime;

	public long getId() {
		return id;
	}

	public void setId(long id) {
		this.id = id;
	}

	public String getTitleName() {
		return titleName;
	}

	public void setTitleName(String titleName) {
		this.titleName = titleName;
	}

	public String getCreator() {
		return creator;
	}

	public void setCreator(String creator) {
		this.creator = creator;
	}

	public Date getCreateTime() {
		return createTime;
	}

	public void setCreateTime(Date createTime) {
		this.createTime = createTime;
	}

	@Override
	public String toString() {
		return String.format("%d\t%s\t%s\t%s", this.id,this.titleName,this.creator,this.createTime);
	}
	
	

}
