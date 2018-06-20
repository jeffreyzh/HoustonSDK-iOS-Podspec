////
////  HoustonUpdater.h
////  Pods
////
////  Created by 昆卡 on 16/8/27.
////
////

#import <Foundation/Foundation.h>
#import "HoustonRequestProtocol.h"
#import <MWP-iOS-Open/RemoteMCommand.h>

@interface HoustonMWPRequestAdapter : NSObject<HoustonRequestProtocol>
@end

@interface HoustonMWPListenner : NSObject <RemoteMCommandListener>

@end

