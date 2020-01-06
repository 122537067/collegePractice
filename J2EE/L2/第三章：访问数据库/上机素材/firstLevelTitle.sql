if exists (select * from dbo.sysobjects where id = object_id(N'[dbo].[FirstLevelTitle]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[FirstLevelTitle]
GO

CREATE TABLE [dbo].[FirstLevelTitle] (
	[Id] [numeric](18, 0) NOT NULL ,
	[TitleName] [varchar] (50) COLLATE Chinese_PRC_CI_AS NOT NULL ,
	[Creator] [varchar] (50) COLLATE Chinese_PRC_CI_AS NOT NULL ,
	[CreateTime] [datetime] NOT NULL 
) ON [PRIMARY]
GO

