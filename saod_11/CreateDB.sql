USE [LockeyDB]
GO
/****** Object:  Table [dbo].[ActionDescription]    Script Date: 02.01.2020 12:23:12 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[ActionDescription](
	[ActionID] [int] IDENTITY(1,1) NOT NULL,
	[Description] [nvarchar](200) NOT NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [ActionDescription_PK] PRIMARY KEY CLUSTERED 
(
	[ActionID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Alert]    Script Date: 02.01.2020 12:23:12 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Alert](
	[AlertID] [int] IDENTITY(1,1) NOT NULL,
	[AlertOccuranceDate] [datetime] NOT NULL,
	[AlertTypeID] [int] NULL,
	[AlertShownUserMapID] [int] NULL,
	[AlertDBCreationDate] [datetime] NULL,
	[AlertShownDate] [datetime] NULL,
	[AlertDeliveredDate] [datetime] NULL,
	[AlertClosedDate] [datetime] NULL,
	[AlertDeliveredUserMapID] [int] NULL,
	[AlertClosedUserMapID] [int] NULL,
	[Comment] [nvarchar](250) NULL,
	[IMEI] [varchar](50) NOT NULL,
	[TVersion] [timestamp] NOT NULL,
	[EventCodeID] [int] NULL,
	[EventParam] [int] NULL,
 CONSTRAINT [Alert_PK] PRIMARY KEY CLUSTERED 
(
	[AlertID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[AlertTypeDictionary]    Script Date: 02.01.2020 12:23:12 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[AlertTypeDictionary](
	[AlertTypeID] [int] NOT NULL,
	[AlertDescription] [nvarchar](250) NULL,
	[AlertName] [nvarchar](250) NOT NULL,
	[AlertShouldNotify] [bit] NULL,
	[IsActual] [bit] NOT NULL,
	[TVersion] [timestamp] NOT NULL,
	[EventGroupID] [int] NULL,
 CONSTRAINT [PK_AlertTypeDictionary] PRIMARY KEY CLUSTERED 
(
	[AlertTypeID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[aspnet_Applications]    Script Date: 02.01.2020 12:23:12 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[aspnet_Applications](
	[ApplicationName] [nvarchar](256) NOT NULL,
	[LoweredApplicationName] [nvarchar](256) NOT NULL,
	[ApplicationId] [uniqueidentifier] NOT NULL,
	[Description] [nvarchar](256) NULL,
PRIMARY KEY NONCLUSTERED 
(
	[ApplicationId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY],
UNIQUE NONCLUSTERED 
(
	[LoweredApplicationName] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY],
UNIQUE NONCLUSTERED 
(
	[ApplicationName] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[aspnet_Membership]    Script Date: 02.01.2020 12:23:12 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[aspnet_Membership](
	[ApplicationId] [uniqueidentifier] NOT NULL,
	[UserId] [uniqueidentifier] NOT NULL,
	[Password] [nvarchar](128) NOT NULL,
	[PasswordFormat] [int] NOT NULL,
	[PasswordSalt] [nvarchar](128) NOT NULL,
	[MobilePIN] [nvarchar](16) NULL,
	[Email] [nvarchar](256) NULL,
	[LoweredEmail] [nvarchar](256) NULL,
	[PasswordQuestion] [nvarchar](256) NULL,
	[PasswordAnswer] [nvarchar](128) NULL,
	[IsApproved] [bit] NOT NULL,
	[IsLockedOut] [bit] NOT NULL,
	[CreateDate] [datetime] NOT NULL,
	[LastLoginDate] [datetime] NOT NULL,
	[LastPasswordChangedDate] [datetime] NOT NULL,
	[LastLockoutDate] [datetime] NOT NULL,
	[FailedPasswordAttemptCount] [int] NOT NULL,
	[FailedPasswordAttemptWindowStart] [datetime] NOT NULL,
	[FailedPasswordAnswerAttemptCount] [int] NOT NULL,
	[FailedPasswordAnswerAttemptWindowStart] [datetime] NOT NULL,
	[Comment] [ntext] NULL,
PRIMARY KEY NONCLUSTERED 
(
	[UserId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
/****** Object:  Table [dbo].[aspnet_Paths]    Script Date: 02.01.2020 12:23:13 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[aspnet_Paths](
	[ApplicationId] [uniqueidentifier] NOT NULL,
	[PathId] [uniqueidentifier] NOT NULL,
	[Path] [nvarchar](256) NOT NULL,
	[LoweredPath] [nvarchar](256) NOT NULL,
PRIMARY KEY NONCLUSTERED 
(
	[PathId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[aspnet_PersonalizationAllUsers]    Script Date: 02.01.2020 12:23:13 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[aspnet_PersonalizationAllUsers](
	[PathId] [uniqueidentifier] NOT NULL,
	[PageSettings] [image] NOT NULL,
	[LastUpdatedDate] [datetime] NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[PathId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
/****** Object:  Table [dbo].[aspnet_PersonalizationPerUser]    Script Date: 02.01.2020 12:23:13 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[aspnet_PersonalizationPerUser](
	[Id] [uniqueidentifier] NOT NULL,
	[PathId] [uniqueidentifier] NULL,
	[UserId] [uniqueidentifier] NULL,
	[PageSettings] [image] NOT NULL,
	[LastUpdatedDate] [datetime] NOT NULL,
PRIMARY KEY NONCLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
/****** Object:  Table [dbo].[aspnet_Profile]    Script Date: 02.01.2020 12:23:13 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[aspnet_Profile](
	[UserId] [uniqueidentifier] NOT NULL,
	[PropertyNames] [ntext] NOT NULL,
	[PropertyValuesString] [ntext] NOT NULL,
	[PropertyValuesBinary] [image] NOT NULL,
	[LastUpdatedDate] [datetime] NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[UserId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
/****** Object:  Table [dbo].[aspnet_Roles]    Script Date: 02.01.2020 12:23:13 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[aspnet_Roles](
	[ApplicationId] [uniqueidentifier] NOT NULL,
	[RoleId] [uniqueidentifier] NOT NULL,
	[RoleName] [nvarchar](256) NOT NULL,
	[LoweredRoleName] [nvarchar](256) NOT NULL,
	[Description] [nvarchar](256) NULL,
PRIMARY KEY NONCLUSTERED 
(
	[RoleId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[aspnet_SchemaVersions]    Script Date: 02.01.2020 12:23:13 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[aspnet_SchemaVersions](
	[Feature] [nvarchar](128) NOT NULL,
	[CompatibleSchemaVersion] [nvarchar](128) NOT NULL,
	[IsCurrentVersion] [bit] NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[Feature] ASC,
	[CompatibleSchemaVersion] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[aspnet_Users]    Script Date: 02.01.2020 12:23:13 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[aspnet_Users](
	[ApplicationId] [uniqueidentifier] NOT NULL,
	[UserId] [uniqueidentifier] NOT NULL,
	[UserName] [nvarchar](256) NOT NULL,
	[LoweredUserName] [nvarchar](256) NOT NULL,
	[MobileAlias] [nvarchar](16) NULL,
	[IsAnonymous] [bit] NOT NULL,
	[LastActivityDate] [datetime] NOT NULL,
PRIMARY KEY NONCLUSTERED 
(
	[UserId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[aspnet_UsersInRoles]    Script Date: 02.01.2020 12:23:13 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[aspnet_UsersInRoles](
	[UserId] [uniqueidentifier] NOT NULL,
	[RoleId] [uniqueidentifier] NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[UserId] ASC,
	[RoleId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[aspnet_WebEvent_Events]    Script Date: 02.01.2020 12:23:13 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[aspnet_WebEvent_Events](
	[EventId] [char](32) NOT NULL,
	[EventTimeUtc] [datetime] NOT NULL,
	[EventTime] [datetime] NOT NULL,
	[EventType] [nvarchar](256) NOT NULL,
	[EventSequence] [decimal](19, 0) NOT NULL,
	[EventOccurrence] [decimal](19, 0) NOT NULL,
	[EventCode] [int] NOT NULL,
	[EventDetailCode] [int] NOT NULL,
	[Message] [nvarchar](1024) NULL,
	[ApplicationPath] [nvarchar](256) NULL,
	[ApplicationVirtualPath] [nvarchar](256) NULL,
	[MachineName] [nvarchar](256) NOT NULL,
	[RequestUrl] [nvarchar](1024) NULL,
	[ExceptionType] [nvarchar](256) NULL,
	[Details] [ntext] NULL,
PRIMARY KEY CLUSTERED 
(
	[EventId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
/****** Object:  Table [dbo].[BeaconToObjectAssignment]    Script Date: 02.01.2020 12:23:13 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[BeaconToObjectAssignment](
	[SNo] [int] IDENTITY(1,1) NOT NULL,
	[StartDate] [datetime] NOT NULL,
	[EndDate] [datetime] NULL,
	[ObjectDeviceID] [int] NOT NULL,
	[ObjectID] [int] NOT NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [BeaconToObjectAssignment_PK] PRIMARY KEY CLUSTERED 
(
	[SNo] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[CarBodyTypeDictionary]    Script Date: 02.01.2020 12:23:13 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[CarBodyTypeDictionary](
	[CarBodyTypeID] [int] IDENTITY(1,1) NOT NULL,
	[CarBodyType] [nvarchar](50) NOT NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [PK_CarBodyTypeDictionary] PRIMARY KEY CLUSTERED 
(
	[CarBodyTypeID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[CarColorDictionary]    Script Date: 02.01.2020 12:23:13 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[CarColorDictionary](
	[CarColorID] [int] IDENTITY(1,1) NOT NULL,
	[CarColor] [nvarchar](50) NOT NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [PK_CarColorDictionary] PRIMARY KEY CLUSTERED 
(
	[CarColorID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[CarInfo]    Script Date: 02.01.2020 12:23:13 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[CarInfo](
	[CarID] [int] IDENTITY(1,1) NOT NULL,
	[CarColorID] [int] NOT NULL,
	[CarPhoto] [uniqueidentifier] NULL,
	[CarManufacturer] [nvarchar](32) NOT NULL,
	[CarModel] [nvarchar](32) NOT NULL,
	[CarReleaseYear] [char](10) NULL,
	[CarBodyTypeID] [int] NULL,
	[VIN] [nvarchar](32) NOT NULL,
	[CarCaller] [nvarchar](32) NULL,
	[CarRegNumber] [nvarchar](16) NOT NULL,
	[CarEngineNumber] [nvarchar](16) NOT NULL,
	[CarChassisNumber] [nvarchar](16) NOT NULL,
	[ObjectID] [int] NOT NULL,
	[TVersion] [timestamp] NOT NULL,
	[HasCamera] [tinyint] NOT NULL,
	[DriverFName] [nvarchar](20) NOT NULL,
	[DriverMName] [nvarchar](20) NOT NULL,
	[DriverLName] [nvarchar](20) NOT NULL,
	[DriverPhone] [nvarchar](15) NOT NULL,
	[FuelTankVolume] [int] NOT NULL,
	[InstallLocation] [nvarchar](128) NULL,
 CONSTRAINT [PK_CarInfo] PRIMARY KEY NONCLUSTERED 
(
	[CarID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[CarSensor]    Script Date: 02.01.2020 12:23:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[CarSensor](
	[SensorID] [int] IDENTITY(1,1) NOT NULL,
	[SNo] [int] NOT NULL,
	[CarSensorTypeID] [int] NOT NULL,
	[RegDate] [datetime] NOT NULL,
	[TVersion] [timestamp] NOT NULL,
	[SensorXMLParam] [xml] NULL,
 CONSTRAINT [PK_CarSensor] PRIMARY KEY CLUSTERED 
(
	[SensorID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
/****** Object:  Table [dbo].[CarSensorTypeDictionary]    Script Date: 02.01.2020 12:23:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[CarSensorTypeDictionary](
	[CarSensorTypeID] [int] IDENTITY(1,1) NOT NULL,
	[CarSensorType] [varchar](32) NOT NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [PK_CarSensorTypeDictionary] PRIMARY KEY CLUSTERED 
(
	[CarSensorTypeID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[CarToGroup]    Script Date: 02.01.2020 12:23:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[CarToGroup](
	[CarToGroupID] [int] IDENTITY(1,1) NOT NULL,
	[ObjectID] [int] NOT NULL,
	[GroupID] [int] NOT NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [CarToGroup_PK] PRIMARY KEY CLUSTERED 
(
	[CarToGroupID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[CarToService]    Script Date: 02.01.2020 12:23:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[CarToService](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[ObjectID] [int] NOT NULL,
	[ServiceID] [int] NOT NULL,
	[StartDate] [datetime] NOT NULL,
	[EndDate] [datetime] NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [PK_CarToService] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[ClientToService]    Script Date: 02.01.2020 12:23:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[ClientToService](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[OwnerID] [int] NOT NULL,
	[ServiceID] [int] NOT NULL,
	[StartDate] [datetime] NOT NULL,
	[EndDate] [datetime] NULL,
	[TVersion] [timestamp] NOT NULL,
	[HistoryOnID] [int] NOT NULL,
	[HistoryOffID] [int] NULL,
	[ServiceParams] [xml] NULL,
 CONSTRAINT [PK_ClientToService] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Command]    Script Date: 02.01.2020 12:23:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Command](
	[CommandID] [int] IDENTITY(1,1) NOT NULL,
	[CommandActionID] [int] NOT NULL,
	[CommandOnlineID] [int] NOT NULL,
	[CommandOccuranceDate] [datetime] NOT NULL,
	[CommandReadDate] [datetime] NULL,
	[Ackowledged] [bit] NOT NULL,
	[SenderComment] [nvarchar](200) NULL,
	[UserMapID] [int] NOT NULL,
	[IMEI] [varchar](50) NOT NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [Command_PK] PRIMARY KEY CLUSTERED 
(
	[CommandID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[CommandAction]    Script Date: 02.01.2020 12:23:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[CommandAction](
	[CommandActionID] [int] IDENTITY(1,1) NOT NULL,
	[CommandTypeID] [int] NOT NULL,
	[SNo] [int] NOT NULL,
	[ActionID] [int] NOT NULL,
	[IsActual] [bit] NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [CommandAction_PK] PRIMARY KEY CLUSTERED 
(
	[CommandActionID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[CommandTypeDictionary]    Script Date: 02.01.2020 12:23:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[CommandTypeDictionary](
	[CommandTypeID] [int] IDENTITY(1,1) NOT NULL,
	[ObjectDeviceTypeID] [int] NOT NULL,
	[CommandDescription] [char](64) NOT NULL,
	[CommandCode] [int] NOT NULL,
	[CommandArg_1] [int] NULL,
	[CommandArg_2] [int] NULL,
	[CommandText] [nvarchar](500) NULL,
	[IsActual] [bit] NULL,
	[TVersion] [timestamp] NOT NULL,
	[DefaultActionID] [int] NULL,
 CONSTRAINT [CommandTypeDictionary_PK] PRIMARY KEY CLUSTERED 
(
	[CommandTypeID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[DeliveryTypeDictionary]    Script Date: 02.01.2020 12:23:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[DeliveryTypeDictionary](
	[DeliveryTypeID] [int] IDENTITY(1,1) NOT NULL,
	[DeliveryTypeName] [nvarchar](50) NOT NULL,
	[HasSound] [bit] NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [DeliveryTypeDictionary_PK] PRIMARY KEY CLUSTERED 
(
	[DeliveryTypeID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[DeviceHistory]    Script Date: 02.01.2020 12:23:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[DeviceHistory](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[StartDate] [datetime] NOT NULL,
	[EndDate] [datetime] NULL,
	[ObjectDeviceID] [int] NOT NULL,
	[OwnerID] [int] NULL,
	[UserMapID] [int] NOT NULL,
	[Comment] [nvarchar](250) NULL,
	[DistributorID] [int] NULL,
	[TVersion] [timestamp] NOT NULL,
	[DistributorStoreID] [int] NULL,
	[ObjectID] [int] NULL,
	[IsBroken] [bit] NOT NULL,
 CONSTRAINT [DeviceHistory_PK] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[DeviceLog]    Script Date: 02.01.2020 12:23:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[DeviceLog](
	[DeviceLogID] [int] IDENTITY(1,1) NOT NULL,
	[ObjectDeviceID] [int] NOT NULL,
	[UserName] [nvarchar](32) NOT NULL,
	[ActionDate] [datetime] NOT NULL,
	[Comment] [nvarchar](2048) NOT NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [DeviceLog_PK] PRIMARY KEY CLUSTERED 
(
	[DeviceLogID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[DeviceStore]    Script Date: 02.01.2020 12:23:14 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[DeviceStore](
	[DeviceStoreId] [int] IDENTITY(1,1) NOT NULL,
	[OwnerID] [int] NULL,
	[DeviceID] [int] NOT NULL,
	[DistributorStoreID] [int] NULL,
	[IsBroken] [bit] NOT NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [PK_DeviceStore] PRIMARY KEY CLUSTERED 
(
	[DeviceStoreId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY],
UNIQUE NONCLUSTERED 
(
	[DeviceID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[DeviceToObjectAssignment]    Script Date: 02.01.2020 12:23:15 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[DeviceToObjectAssignment](
	[SNo] [int] IDENTITY(1,1) NOT NULL,
	[StartDate] [datetime] NOT NULL,
	[EndDate] [datetime] NULL,
	[ObjectDeviceID] [int] NOT NULL,
	[ObjectID] [int] NOT NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [DeviceToObjectAssignment_PK] PRIMARY KEY CLUSTERED 
(
	[SNo] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Distributor]    Script Date: 02.01.2020 12:23:15 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Distributor](
	[DistributorID] [int] IDENTITY(1,1) NOT NULL,
	[DistributorRootID] [int] NULL,
	[DistributorTitle] [nvarchar](50) NOT NULL,
	[DistributorContactName] [nvarchar](80) NULL,
	[Phone] [char](20) NULL,
	[Address] [nvarchar](250) NULL,
	[Mail] [varchar](50) NULL,
	[RegDate] [datetime] NULL,
	[IsActive] [bit] NOT NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [Distributor_PK] PRIMARY KEY CLUSTERED 
(
	[DistributorID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[DistributorStoreDictionary]    Script Date: 02.01.2020 12:23:15 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[DistributorStoreDictionary](
	[DistributorStoreID] [int] IDENTITY(1,1) NOT NULL,
	[DistrStoreTitle] [nvarchar](50) NOT NULL,
	[DistrStoreComment] [nvarchar](200) NULL,
	[DistributorID] [int] NOT NULL,
	[IsActive] [bit] NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [DistributorStoreDictionary_PK] PRIMARY KEY CLUSTERED 
(
	[DistributorStoreID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[EventCodeDictionary]    Script Date: 02.01.2020 12:23:15 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[EventCodeDictionary](
	[EventCodeID] [int] NOT NULL,
	[EventCodeDescription] [nvarchar](200) NOT NULL,
	[IsActive] [bit] NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [EventCodeDictionary_PK] PRIMARY KEY CLUSTERED 
(
	[EventCodeID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[EventGroup]    Script Date: 02.01.2020 12:23:15 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[EventGroup](
	[EventGroupID] [int] IDENTITY(1,1) NOT NULL,
	[EventGroupName] [nvarchar](100) NOT NULL,
	[IsActive] [bit] NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [EventGroup_PK] PRIMARY KEY CLUSTERED 
(
	[EventGroupID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[EventTranslator]    Script Date: 02.01.2020 12:23:15 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[EventTranslator](
	[ETID] [int] IDENTITY(1,1) NOT NULL,
	[EventCodeID] [int] NOT NULL,
	[SNo] [int] NOT NULL,
	[AlertTypeID] [int] NOT NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [EventTranslator_PK] PRIMARY KEY CLUSTERED 
(
	[ETID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[GeneratedAlertStatus]    Script Date: 02.01.2020 12:23:15 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[GeneratedAlertStatus](
	[IMEI] [varchar](50) NOT NULL,
	[NoSignalStatus] [bit] NULL,
	[NoCoordStatus] [bit] NULL,
	[TVersion] [timestamp] NOT NULL,
	[Mask] [int] NULL
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[GlobalSettings]    Script Date: 02.01.2020 12:23:15 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[GlobalSettings](
	[SettingsID] [int] IDENTITY(1,1) NOT NULL,
	[SettingName] [nvarchar](50) NOT NULL,
	[StrSettingVal] [nvarchar](250) NULL,
	[IntSettingVal] [int] NULL,
	[DateSettingVal] [datetime] NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [PK_GlobalSettings] PRIMARY KEY CLUSTERED 
(
	[SettingsID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[GuardAssignment]    Script Date: 02.01.2020 12:23:29 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[GuardAssignment](
	[GuardAssignmentID] [int] IDENTITY(1,1) NOT NULL,
	[GuardID] [int] NOT NULL,
	[UserMapID] [int] NOT NULL,
	[StartDate] [datetime] NOT NULL,
	[FinishDate] [datetime] NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [PK_DutyLog] PRIMARY KEY CLUSTERED 
(
	[GuardAssignmentID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[GuardOrder]    Script Date: 02.01.2020 12:23:29 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[GuardOrder](
	[GuardOrderID] [int] IDENTITY(1,1) NOT NULL,
	[Name] [nvarchar](50) NOT NULL,
	[RegDate] [datetime] NOT NULL,
	[IsActual] [bit] NOT NULL,
	[DistributorID] [int] NOT NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [Id_GuardOrder_PK] PRIMARY KEY CLUSTERED 
(
	[GuardOrderID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[GuardOrderList]    Script Date: 02.01.2020 12:23:29 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[GuardOrderList](
	[GuardOrderListID] [int] IDENTITY(1,1) NOT NULL,
	[GuardID] [int] NOT NULL,
	[CarID] [int] NOT NULL,
	[FromDate] [datetime] NOT NULL,
	[ToDate] [datetime] NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [PK_GuardOrderList] PRIMARY KEY CLUSTERED 
(
	[GuardOrderListID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[HistoryAction]    Script Date: 02.01.2020 12:23:29 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[HistoryAction](
	[ActionID] [int] IDENTITY(1,1) NOT NULL,
	[Name] [nchar](200) NOT NULL,
 CONSTRAINT [PK_HistoryAction] PRIMARY KEY CLUSTERED 
(
	[ActionID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[HistoryDetails]    Script Date: 02.01.2020 12:23:29 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[HistoryDetails](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[UserMapID] [int] NOT NULL,
	[Comment] [nvarchar](250) NULL,
	[TVestion] [timestamp] NOT NULL,
 CONSTRAINT [PK_HistoryDetails] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[HistoryDictionary]    Script Date: 02.01.2020 12:23:29 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[HistoryDictionary](
	[DictionaryID] [int] IDENTITY(1,1) NOT NULL,
	[PageID] [int] NOT NULL,
	[ActionID] [int] NOT NULL,
	[Description] [nvarchar](200) NULL,
 CONSTRAINT [PK_HistoryDictionary] PRIMARY KEY CLUSTERED 
(
	[DictionaryID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[HistoryEvent]    Script Date: 02.01.2020 12:23:29 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[HistoryEvent](
	[EventID] [int] IDENTITY(1,1) NOT NULL,
	[DictionaryID] [int] NULL,
	[UserID] [uniqueidentifier] NOT NULL,
	[EventDate] [datetime] NOT NULL,
 CONSTRAINT [PK_HistoryEvent] PRIMARY KEY CLUSTERED 
(
	[EventID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[HistoryEventOption]    Script Date: 02.01.2020 12:23:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[HistoryEventOption](
	[EventOptionID] [int] NOT NULL,
	[Options] [nvarchar](200) NULL,
	[ReportID] [int] NULL,
 CONSTRAINT [PK_HistoryEventOption] PRIMARY KEY CLUSTERED 
(
	[EventOptionID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[HistoryPage]    Script Date: 02.01.2020 12:23:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[HistoryPage](
	[PageID] [int] IDENTITY(1,1) NOT NULL,
	[Name] [nchar](200) NOT NULL,
 CONSTRAINT [PK_HistoryPage] PRIMARY KEY CLUSTERED 
(
	[PageID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[LockeyUser]    Script Date: 02.01.2020 12:23:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[LockeyUser](
	[OwnerID] [int] NULL,
	[DistributorID] [int] NULL,
	[UserMapID] [int] IDENTITY(1,1) NOT NULL,
	[UserID] [uniqueidentifier] NOT NULL,
	[FirstName] [nvarchar](50) NOT NULL,
	[LastName] [nvarchar](50) NOT NULL,
	[MiddleName] [nvarchar](50) NULL,
	[TVersion] [timestamp] NOT NULL,
	[PhoneNumber] [varchar](32) NULL,
 CONSTRAINT [UserMap_PK] PRIMARY KEY CLUSTERED 
(
	[UserMapID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[MessageQueue]    Script Date: 02.01.2020 12:23:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[MessageQueue](
	[MessageID] [int] IDENTITY(1,1) NOT NULL,
	[AlertID] [int] NOT NULL,
	[SubscriptionID] [int] NOT NULL,
	[CreationDate] [datetime] NOT NULL,
	[DeliveryDate] [datetime] NULL,
	[ConfirmDate] [datetime] NULL,
	[DeliveryTypeID] [int] NOT NULL,
	[ObjectID] [int] NOT NULL,
	[UserMapID] [int] NOT NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [MessageQueue_PK] PRIMARY KEY CLUSTERED 
(
	[MessageID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Object]    Script Date: 02.01.2020 12:23:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Object](
	[ObjectID] [int] IDENTITY(1,1) NOT NULL,
	[ObjectTypeID] [int] NOT NULL,
	[OwnerID] [int] NOT NULL,
	[RegDate] [datetime] NULL,
	[Properties] [xml] NULL,
	[IsActive] [bit] NOT NULL,
	[LastUpdated] [datetime] NOT NULL,
	[TVersion] [timestamp] NOT NULL,
	[ObjectName] [nvarchar](250) NOT NULL,
 CONSTRAINT [Object_PK] PRIMARY KEY CLUSTERED 
(
	[ObjectID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
/****** Object:  Table [dbo].[ObjectActivityLog]    Script Date: 02.01.2020 12:23:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[ObjectActivityLog](
	[ObjectActivityID] [int] IDENTITY(1,1) NOT NULL,
	[IsActive] [bit] NOT NULL,
	[Date] [datetime] NOT NULL,
	[ObjectID] [int] NOT NULL,
	[UserMapID] [int] NOT NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [PK_ObjectActivityLog] PRIMARY KEY CLUSTERED 
(
	[ObjectActivityID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[ObjectDevice]    Script Date: 02.01.2020 12:23:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[ObjectDevice](
	[ObjectDeviceID] [int] IDENTITY(1,1) NOT NULL,
	[CustomDeviceID] [int] NOT NULL,
	[IMEI] [varchar](50) NOT NULL,
	[SIM] [varchar](50) NOT NULL,
	[IsActive] [bit] NOT NULL,
	[ObjectDeviceTypeID] [int] NOT NULL,
	[ActivationRequired] [bit] NULL,
	[ActivationKey] [nvarchar](20) NULL,
	[ObjectHasGPRS] [bit] NOT NULL,
	[ICounter] [int] NOT NULL,
	[DataServerIP] [varchar](50) NULL,
	[DataServerPort] [int] NULL,
	[DataPeriod] [int] NULL,
	[LastContact] [datetime] NULL,
	[ObjectDeviceRegDate] [datetime] NULL,
	[GPRSpwd] [nvarchar](50) NOT NULL,
	[HasVideo] [tinyint] NOT NULL,
	[TVersion] [timestamp] NOT NULL,
	[SIMCardNum] [varchar](32) NULL,
	[VInsertion] [varchar](16) NULL,
	[DeviceComment] [nvarchar](200) NULL,
 CONSTRAINT [ObjectDevice_PK] PRIMARY KEY CLUSTERED 
(
	[ObjectDeviceID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY],
UNIQUE NONCLUSTERED 
(
	[IMEI] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY],
UNIQUE NONCLUSTERED 
(
	[CustomDeviceID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[ObjectDeviceSnapShot]    Script Date: 02.01.2020 12:23:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[ObjectDeviceSnapShot](
	[DeviceSnapShotID] [int] IDENTITY(1,1) NOT NULL,
	[PositionLatitude] [float] NOT NULL,
	[PositionLongitude] [float] NOT NULL,
	[PositionSpeed] [float] NULL,
	[PositionAltitude] [int] NULL,
	[PositionAddress] [varchar](150) NULL,
	[PositionOccuranceDate] [datetime] NOT NULL,
	[PositionEntryDate] [datetime] NOT NULL,
	[IMEI] [varchar](50) NOT NULL,
	[PositionBortdate] [datetime] NOT NULL,
	[PositionLastOccuranceDate] [datetime] NOT NULL,
	[PositionLastBortdate] [datetime] NOT NULL,
	[PositionLastEntryDate] [datetime] NOT NULL,
	[TVersion] [timestamp] NOT NULL,
	[Course] [smallint] NOT NULL,
 CONSTRAINT [ObjectDeviceSnapShot_PK] PRIMARY KEY CLUSTERED 
(
	[DeviceSnapShotID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[ObjectDeviceTypeDictionary]    Script Date: 02.01.2020 12:23:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[ObjectDeviceTypeDictionary](
	[ObjectDeviceTypeID] [int] IDENTITY(1,1) NOT NULL,
	[DeviceType] [nvarchar](20) NOT NULL,
	[DeviceTypeVersion] [char](10) NULL,
	[DeviceTypeSWVersion] [char](10) NULL,
	[IsActual] [bit] NULL,
	[TVersion] [timestamp] NOT NULL,
	[FunctionFlags] [int] NOT NULL,
 CONSTRAINT [ObjectDeviceTypeDictionary_PK] PRIMARY KEY CLUSTERED 
(
	[ObjectDeviceTypeID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[ObjectImage]    Script Date: 02.01.2020 12:23:31 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[ObjectImage](
	[ImageID] [uniqueidentifier] NOT NULL,
	[ObjectPicture] [image] NULL,
	[LastUpdated] [datetime] NOT NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [PK_ObjectImage] PRIMARY KEY CLUSTERED 
(
	[ImageID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
/****** Object:  Table [dbo].[ObjectStatus]    Script Date: 02.01.2020 12:23:31 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[ObjectStatus](
	[ObjectStatusID] [int] IDENTITY(1,1) NOT NULL,
	[ObjectID] [int] NOT NULL,
	[StatusTypeID] [int] NOT NULL,
	[StartDate] [datetime] NOT NULL,
	[EndDate] [datetime] NULL,
	[Comment] [nvarchar](150) NULL,
	[UserMapID] [int] NOT NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [ObjectStatus_PK] PRIMARY KEY CLUSTERED 
(
	[ObjectStatusID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[ObjectStatusSnapShot]    Script Date: 02.01.2020 12:23:31 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[ObjectStatusSnapShot](
	[ObjectStatusSnapShotID] [int] IDENTITY(1,1) NOT NULL,
	[OccuranceDate] [datetime] NOT NULL,
	[StatusTypeID] [int] NOT NULL,
	[EntryDate] [datetime] NULL,
	[IMEI] [varchar](50) NOT NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [ObjectStatusSnapShot_PK] PRIMARY KEY CLUSTERED 
(
	[ObjectStatusSnapShotID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[ObjectToRoute]    Script Date: 02.01.2020 12:23:31 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[ObjectToRoute](
	[RouteToObjectID] [int] IDENTITY(1,1) NOT NULL,
	[RouteID] [int] NOT NULL,
	[RouteExpireTime] [datetime] NOT NULL,
	[ObjectID] [int] NOT NULL,
	[UserMapID] [int] NOT NULL,
	[RegDate] [datetime] NOT NULL,
	[Calendar] [xml] NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [ObjectToRoute_PK] PRIMARY KEY CLUSTERED 
(
	[RouteToObjectID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
/****** Object:  Table [dbo].[ObserveGroups]    Script Date: 02.01.2020 12:23:31 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[ObserveGroups](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[OwnerID] [int] NOT NULL,
	[GroupList] [xml] NULL,
 CONSTRAINT [PK_ObserveGroups] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Owner]    Script Date: 02.01.2020 12:23:31 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Owner](
	[OwnerID] [int] IDENTITY(1,1) NOT NULL,
	[FirstName] [nvarchar](50) NOT NULL,
	[DistributorID] [int] NOT NULL,
	[MiddleName] [nvarchar](50) NULL,
	[LastName] [varchar](50) NOT NULL,
	[Address] [nvarchar](250) NULL,
	[HomePhone] [nvarchar](50) NULL,
	[MobilePhone] [nvarchar](50) NULL,
	[WorkPhone] [nvarchar](50) NULL,
	[RegDate] [datetime] NULL,
	[OwnerMail] [nvarchar](50) NULL,
	[Organization] [nvarchar](50) NULL,
	[OwnerTypeDictionaryID] [int] NOT NULL,
	[IsActive] [bit] NOT NULL,
	[CodeWord] [nvarchar](50) NOT NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [Owner_PK] PRIMARY KEY CLUSTERED 
(
	[OwnerID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[OwnerPaymentInfo]    Script Date: 02.01.2020 12:23:31 ******/
SET ANSI_NULLS OFF
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[OwnerPaymentInfo](
	[OwnerPaymentID] [int] IDENTITY(1,1) NOT NULL,
	[OwnerID] [int] NOT NULL,
	[OwnerPaymentCode] [nvarchar](50) NOT NULL,
 CONSTRAINT [PK_OwnerPaymentInfo] PRIMARY KEY CLUSTERED 
(
	[OwnerPaymentID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[OwnerTypeDictionary]    Script Date: 02.01.2020 12:23:31 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[OwnerTypeDictionary](
	[OwnerTypeDictionaryID] [int] IDENTITY(1,1) NOT NULL,
	[OwnerTypeDescription] [nvarchar](20) NOT NULL,
	[IsActual] [bit] NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [OwnerTypeDictionary_PK] PRIMARY KEY CLUSTERED 
(
	[OwnerTypeDictionaryID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[ProblemReport]    Script Date: 02.01.2020 12:23:31 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[ProblemReport](
	[ProblemID] [int] IDENTITY(1,1) NOT NULL,
	[AuthorID] [int] NOT NULL,
	[AuthorName] [nvarchar](128) NOT NULL,
	[AuthorPhone] [nvarchar](50) NULL,
	[AuthorMail] [nvarchar](50) NULL,
	[CreationDate] [datetime] NOT NULL,
	[ProblemDesc] [nvarchar](max) NOT NULL,
	[ProblemImg] [varbinary](max) NULL,
	[ProblemState] [int] NOT NULL,
	[UserClosedID] [int] NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [ProblemReport_PK] PRIMARY KEY CLUSTERED 
(
	[ProblemID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
/****** Object:  Table [dbo].[ProfileSample]    Script Date: 02.01.2020 12:23:31 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[ProfileSample](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[Title] [varchar](64) NOT NULL,
	[DefaultValuesXML] [xml] NOT NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [ID_PK] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
/****** Object:  Table [dbo].[ReportArchive]    Script Date: 02.01.2020 12:23:31 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[ReportArchive](
	[ReportID] [int] IDENTITY(1,1) NOT NULL,
	[FromDate] [datetime] NOT NULL,
	[ToDate] [datetime] NOT NULL,
	[CreationDate] [datetime] NOT NULL,
	[MinWorkTime] [real] NOT NULL,
	[VersionReport] [int] NOT NULL,
 CONSTRAINT [PK_ReportArchive] PRIMARY KEY CLUSTERED 
(
	[ReportID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[ReportArchiveData]    Script Date: 02.01.2020 12:23:32 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[ReportArchiveData](
	[ReportDataID] [int] IDENTITY(1,1) NOT NULL,
	[ClientID] [int] NULL,
	[ReportID] [int] NULL,
	[CountCars] [int] NOT NULL,
	[CountNotActiveCars] [int] NULL,
	[CountSuspendCars] [int] NOT NULL,
	[CountNotWorkingCars] [int] NOT NULL,
 CONSTRAINT [PK_ReportArchiveData] PRIMARY KEY CLUSTERED 
(
	[ReportDataID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Route]    Script Date: 02.01.2020 12:23:32 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Route](
	[RouteID] [int] IDENTITY(1,1) NOT NULL,
	[RouteDescription] [char](10) NOT NULL,
	[OwnerID] [int] NULL,
	[IsActive] [bit] NOT NULL,
	[LastUpdated] [datetime] NOT NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [Route_PK] PRIMARY KEY CLUSTERED 
(
	[RouteID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[RouteDetails]    Script Date: 02.01.2020 12:23:32 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[RouteDetails](
	[RouteID] [int] IDENTITY(1,1) NOT NULL,
	[Points] [xml] NOT NULL,
	[Stops] [xml] NOT NULL,
	[IsActive] [bit] NOT NULL,
	[Name] [nvarchar](64) NOT NULL,
	[TimeInMinutes] [int] NOT NULL,
	[OwnerID] [int] NOT NULL,
 CONSTRAINT [RouteDetails_PK] PRIMARY KEY CLUSTERED 
(
	[RouteID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Services]    Script Date: 02.01.2020 12:23:32 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Services](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[Title] [nvarchar](64) NOT NULL,
	[IsClient] [bit] NOT NULL,
	[IsActive] [bit] NOT NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [PK_LWServices] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[SmsHistory]    Script Date: 02.01.2020 12:23:32 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[SmsHistory](
	[HistoryID] [int] IDENTITY(1,1) NOT NULL,
	[UserName] [nvarchar](256) NOT NULL,
	[SentDate] [datetime] NOT NULL,
	[Amount] [int] NOT NULL,
 CONSTRAINT [SmsHistory_PK] PRIMARY KEY CLUSTERED 
(
	[HistoryID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[StatusTypeDictionary]    Script Date: 02.01.2020 12:23:32 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[StatusTypeDictionary](
	[StatusTypeID] [int] IDENTITY(1,1) NOT NULL,
	[StatusDescription] [nvarchar](150) NULL,
	[StatusTitle] [nvarchar](50) NOT NULL,
	[IsActual] [bit] NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [StatusTypeDictionary_PK] PRIMARY KEY CLUSTERED 
(
	[StatusTypeID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Subscription]    Script Date: 02.01.2020 12:23:32 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Subscription](
	[SubscriptionID] [int] IDENTITY(1,1) NOT NULL,
	[Title] [varchar](64) NOT NULL,
	[UserMapID] [int] NOT NULL,
	[IsActive] [bit] NOT NULL,
	[TVersion] [timestamp] NOT NULL,
	[StartTime] [time](0) NULL,
	[EndTime] [time](0) NULL,
 CONSTRAINT [PK_Subscription] PRIMARY KEY CLUSTERED 
(
	[SubscriptionID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[SubscriptionDelivery]    Script Date: 02.01.2020 12:23:32 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[SubscriptionDelivery](
	[SubscriptionID] [int] NOT NULL,
	[DeliveryTypeID] [int] NOT NULL,
	[PlaySound] [bit] NOT NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [SubscriptionDelivery_PK] PRIMARY KEY CLUSTERED 
(
	[SubscriptionID] ASC,
	[DeliveryTypeID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[SubscriptionEvent]    Script Date: 02.01.2020 12:23:32 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[SubscriptionEvent](
	[SubscriptionID] [int] NOT NULL,
	[EventGroupID] [int] NOT NULL,
	[TVersion] [timestamp] NOT NULL,
	[EventParam] [int] NULL,
 CONSTRAINT [PK_SubscriptionEvent] PRIMARY KEY CLUSTERED 
(
	[SubscriptionID] ASC,
	[EventGroupID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[SubscriptionObject]    Script Date: 02.01.2020 12:23:32 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[SubscriptionObject](
	[SubscriptionID] [int] NOT NULL,
	[ObjectID] [int] NOT NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [PK_SubscriptionObject] PRIMARY KEY CLUSTERED 
(
	[SubscriptionID] ASC,
	[ObjectID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[SubscriptionParams]    Script Date: 02.01.2020 12:23:32 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[SubscriptionParams](
	[SubscriptionID] [int] NOT NULL,
	[DeliveryTypeID] [int] NOT NULL,
	[Value] [varchar](3200) NOT NULL,
 CONSTRAINT [PK_SubscriptionParams] PRIMARY KEY CLUSTERED 
(
	[SubscriptionID] ASC,
	[DeliveryTypeID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[SubsriptionZoneEvent]    Script Date: 02.01.2020 12:23:32 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[SubsriptionZoneEvent](
	[SubscriptionID] [int] NOT NULL,
	[EventGroupID] [int] NOT NULL,
	[ZoneID] [int] NOT NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [PK_SubscriptionZoneEvent] PRIMARY KEY CLUSTERED 
(
	[SubscriptionID] ASC,
	[EventGroupID] ASC,
	[ZoneID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[TmpOrder]    Script Date: 02.01.2020 12:23:32 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[TmpOrder](
	[OrderID] [int] IDENTITY(1,1) NOT NULL,
	[Operator] [varchar](15) NOT NULL,
	[PhoneNumber] [varchar](15) NOT NULL,
 CONSTRAINT [TmpOrder_PK] PRIMARY KEY CLUSTERED 
(
	[OrderID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[TmpSim]    Script Date: 02.01.2020 12:23:32 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[TmpSim](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[Operator] [varchar](15) NOT NULL,
	[PhoneNumber] [varchar](15) NOT NULL,
	[SIM] [varchar](24) NOT NULL,
 CONSTRAINT [TmpSim_PK] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[UserActionLog]    Script Date: 02.01.2020 12:23:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[UserActionLog](
	[UserActionLogID] [int] IDENTITY(1,1) NOT NULL,
	[UserID] [varchar](64) NOT NULL,
	[ActionType] [varchar](8) NOT NULL,
	[ActionDate] [datetime] NOT NULL,
	[ObjectID] [int] NULL,
	[ObjectClassName] [nvarchar](50) NULL,
	[ChangesInfo] [nvarchar](max) NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [UserActionLog_PK] PRIMARY KEY CLUSTERED 
(
	[UserActionLogID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
/****** Object:  Table [dbo].[UserAgreement]    Script Date: 02.01.2020 12:23:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[UserAgreement](
	[UserAgrID] [int] IDENTITY(1,1) NOT NULL,
	[UserMapID] [int] NOT NULL,
	[AgrDate] [datetime] NOT NULL,
	[Accepted] [bit] NOT NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [UserAgreement_PK] PRIMARY KEY CLUSTERED 
(
	[UserAgrID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[VehicleToZone]    Script Date: 02.01.2020 12:23:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[VehicleToZone](
	[VehicleToZoneID] [int] IDENTITY(1,1) NOT NULL,
	[VehicleID] [int] NOT NULL,
	[ZoneID] [int] NOT NULL,
	[FromDate] [datetime] NOT NULL,
	[ToDate] [datetime] NULL,
	[Alerted] [bit] NOT NULL,
	[Calendar] [xml] NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [VehicleToZone_PK] PRIMARY KEY CLUSTERED 
(
	[VehicleToZoneID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
/****** Object:  Table [dbo].[WorkGroup]    Script Date: 02.01.2020 12:23:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[WorkGroup](
	[GroupID] [int] IDENTITY(1,1) NOT NULL,
	[OwnerID] [int] NOT NULL,
	[Name] [char](64) NOT NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [WGroup_PK] PRIMARY KEY CLUSTERED 
(
	[GroupID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Zone]    Script Date: 02.01.2020 12:23:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Zone](
	[ZoneID] [int] IDENTITY(1,1) NOT NULL,
	[Points] [xml] NOT NULL,
	[Name] [nvarchar](64) NOT NULL,
	[OwnerID] [int] NULL,
	[DistributorID] [int] NULL,
	[IsActive] [bit] NOT NULL,
	[LastUpdated] [datetime] NOT NULL,
	[TVersion] [timestamp] NOT NULL,
 CONSTRAINT [Zone_PK] PRIMARY KEY CLUSTERED 
(
	[ZoneID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
