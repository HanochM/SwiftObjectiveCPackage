//
//  DictionaryData.h
//  TechSeeLiveFramework
//
//  Created by Anna Popova on 28/02/2019.
//  Copyright © 2019 techsee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DictionaryData : NSObject <NSCoding>

@property (nonatomic, strong, readonly) NSString *allow;
@property (nonatomic, strong, readonly) NSString *allow_app_screen_share_body;
@property (nonatomic, strong, readonly) NSString *allow_application_share_title;
@property (nonatomic, strong, readonly) NSString *allow_screen_share_allow_button;
@property (nonatomic, strong, readonly) NSString *allow_screen_share_body;
@property (nonatomic, strong, readonly) NSString *allow_screen_share_deny_button;
@property (nonatomic, strong, readonly) NSString *allow_screen_share_title;
@property (nonatomic, strong, readonly) NSString *allow_sharing;
@property (nonatomic, strong, readonly) NSString *app_name;
@property (nonatomic, strong, readonly) NSString *are_you_sure;
@property (nonatomic, strong, readonly) NSString *before_you_leave;
@property (nonatomic, strong, readonly) NSString *cancel_button_text;
@property (nonatomic, strong, readonly) NSString *close_button_text;
@property (nonatomic, strong, readonly) NSString *continue_session;
@property (nonatomic, strong, readonly) NSString *deny;
@property (nonatomic, strong, readonly) NSString *end_now;
@property (nonatomic, strong, readonly) NSString *image_number_text;
@property (nonatomic, strong, readonly) NSString *image_text;
@property (nonatomic, strong, readonly) NSString *initial_body_text;
@property (nonatomic, strong, readonly) NSString *internet_connection_body;
@property (nonatomic, strong, readonly) NSString *internet_connection_title;
@property (nonatomic, strong, readonly) NSString *lottieAnimation;
@property (nonatomic, strong, readonly) NSString *measurementLive;
@property (nonatomic, strong, readonly) NSString *measurementDeviceNotSupported;
@property (nonatomic, strong, readonly) NSString *measurementStartMeasure;
@property (nonatomic, strong, readonly) NSString *measurementSurfaceRecognition;
@property (nonatomic, strong, readonly) NSString *measurementUnrecognizedSurface;
@property (nonatomic, strong, readonly) NSString *next_button_text;
@property (nonatomic, strong, readonly) NSString *powered_by_techsee_text;
@property (nonatomic, strong, readonly) NSString *prev_button_text;
@property (nonatomic, strong, readonly) NSString *retry_button_text;
@property (nonatomic, strong, readonly) NSString *screen_shared;
@property (nonatomic, strong, readonly) NSString *screen_shared_paused;
@property (nonatomic, strong, readonly) NSString *session_expired_body;
@property (nonatomic, strong, readonly) NSString *session_expired_title;
@property (nonatomic, strong, readonly) NSString *visual_support_text;
@property (nonatomic, strong, readonly) NSString *waiting_for_agent;
@property (nonatomic, strong, readonly) NSString *you_are_about_to_end_session;
@property (nonatomic, strong, readonly) NSString *you_are_denying_agent_help;
@property (nonatomic, strong, readonly) NSString *text_message;
@property (nonatomic, strong, readonly) NSString *no_messages_text;
@property (nonatomic, strong, readonly) NSString *goToAppButtonText;
@property (nonatomic, strong, readonly) NSString *connectivityIssueTitleLabel;
@property (nonatomic, strong, readonly) NSString *connectivityIssueBodyMessage;
@property (nonatomic, strong, readonly) NSString *instant_title;
@property (nonatomic, strong, readonly) NSString *instant_start_broadcast;
@property (nonatomic, strong, readonly) NSString *instant_homescreen_button;
@property (nonatomic, strong, readonly) NSString *instant_subtitle_tap_allow;
@property (nonatomic, strong, readonly) NSString *instant_subtitle_screen_shared;
@property (nonatomic, strong, readonly) NSString *instant_subtitle_contact;
@property (nonatomic, strong, readonly) NSString *instant_powered_by_techsee;
@property (nonatomic, strong, readonly) NSString *instant_broadcast;
@property (nonatomic, strong, readonly) NSString *instant_stop_broadcasting;
@property (nonatomic, strong, readonly) NSString *instant_button_allow_capturing;
@property (nonatomic, strong, readonly) NSString *terms_and_conditions;
@property (nonatomic, strong, readonly) NSString *terms;
@property (nonatomic, strong, readonly) NSString *privacy_policy;
@property (nonatomic, strong, readonly) NSString *native_video_permissions;
@property (nonatomic, strong, readonly) NSString *native_video_permissions_join;
@property (nonatomic, strong, readonly) NSString *native_video_tos_title;
@property (nonatomic, strong, readonly) NSString *video_application_title;
@property (nonatomic, strong, readonly) NSString *video_application_subtitle;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithDictionary:(NSDictionary *)infoDict;

@end
