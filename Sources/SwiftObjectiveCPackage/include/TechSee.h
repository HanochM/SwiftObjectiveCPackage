//
//  TechSee.h
//  TechSeeLiveFramework
//
//  Created by TechSee Shlomi on 16/11/2017.
//  Copyright © 2017 techsee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ReplayKit/ReplayKit.h>

#import "DictionaryData.h"


typedef enum : NSUInteger {
    BroadcastStarted,
    BroadcastPaused,
    BroadcastResumed,
    BroadcastFinished,
} BroadcastStatus;

typedef NS_ENUM(NSUInteger, SessionMode) {
    SessionModeUnknown,
    SessionModeVideo,
    SessionModePhoto,
    SessionModeScreenShare,
    SessionModeApplicationShare,
    SessionModeNativeVideo
};

@protocol AuthenticationProtocol <NSObject>
- (void)authenticateSuccessful;
- (void)authenticateFailure:(NSString * _Nullable)error internalError :(NSString * _Nullable)internalError;
@end

@protocol JoinSessionProtocol <NSObject>
- (void)joinSessionSuccessful:(NSString * _Nullable)sdkVersionStatus newSDKVersion:(NSString *_Nullable)newSDKVersion sessionInitialMode:(SessionMode)mode;
- (void)joinSessionFailure:(NSString *_Nonnull)error sdkVersionStatus:(NSString * _Nullable)sdkVersionStatus newSDKVersion:(NSString * _Nullable)newSDKVersion;
@end

@protocol SessionEventsDelegate <NSObject>
@optional
- (void)sessionDidEnd;
- (void)sessionModeChanged:(SessionMode)sessionMode;
@end

@protocol ScreenTOS <NSObject>
- (void)tosApproval:(BOOL)isApprove;
@end

@protocol Cursor <NSObject>
- (void)moveCursor:(CGRect)frame;
- (void)hideCursor;
@end

@protocol TranslationStatusProtocol <NSObject>
@optional
- (void)translationsReceived:(DictionaryData *_Nullable)dictionaryData;
@end

@class TSBranding;

@interface TechSee : NSObject


#pragma mark - TechSee API's -


@property (weak, nonatomic) id <AuthenticationProtocol> _Nullable delegate;
@property (weak, nonatomic) id <JoinSessionProtocol> _Nullable delegateJoinSession;
@property (weak, nonatomic) id <SessionEventsDelegate> _Nullable sessionEventsDelegate;
@property (weak, nonatomic) id <TranslationStatusProtocol> _Nullable translationStatusProtocol;
@property (weak, nonatomic) id <ScreenTOS> _Nullable screenTOS;
@property (weak, nonatomic) id <Cursor> _Nullable cursor;
@property (strong, nonatomic) NSString * _Nullable backendURL;
@property (strong, nonatomic) TSBranding * _Nonnull branding;

- (instancetype _Nonnull )init NS_UNAVAILABLE;
+ (instancetype _Nonnull )shared;
- (void)configureWithApiKey:(NSString * _Nonnull)apiKey apiSecret:(NSString * _Nullable)apiSecret environment:(NSString * _Nonnull)env NS_SWIFT_NAME(configure(apiKey:apiSecret:environment:));
- (void)joinSession: (NSURL *_Nonnull)sessionLink;
- (NSMutableData *_Nullable)getLogs;
- (NSString *_Nonnull)closeSession;
- (void)openChat;


#pragma mark - App extension API's -

- (void)broadcastStarted:(RPBroadcastSampleHandler *_Nonnull)handler;
- (void)broadcastPaused;
- (void)broadcastResumed;
- (void)broadcastFinished;
- (void)processSampleBuffer:(CMSampleBufferRef _Nonnull )sampleBuffer WithSampleBufferType:(RPSampleBufferType)sampleBufferType;
@end
