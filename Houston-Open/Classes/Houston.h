//
//  Houston.h
//  Pods
//
//  Created by 昆卡 on 16/8/24.
//
//

#import <Foundation/Foundation.h>
#import "HoustonRequestProtocol.h"

/**
 *  对外暴露的配置中心类
 */
@interface Houston : NSObject

/**
 * 启动配置中心，默认方法
 */
+ (void)start;

/**
 *  启动配置中心
 */
+ (void)startWithRequestAdapter:(id <HoustonRequestProtocol>)requestAdapter;

/**
 *  本地配置中心版本号
 *
 *  @return
 */
+ (NSString *)houstonVersion;

@end
