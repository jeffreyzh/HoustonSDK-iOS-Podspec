//
//  HoustonUpdater.h
//  Pods
//
//  Created by 昆卡 on 16/8/27.
//
//

#import <Foundation/Foundation.h>
#import "HoustonGroupInfo.h"
#import "HoustonRequestProtocol.h"

typedef void(^HoustonUpdaterCompletedBlock)(NSArray<HoustonGroupInfo *> *groups, NSString *version, NSError *error);


@interface HoustonUpdater : NSObject


/**
 初始化

 @param adapter 具体实现网络请求的实例

 @return 
 */
- (instancetype)initWithAdapter:(id<HoustonRequestProtocol>)adapter;

/**
 *  @author kongkong
 *
 *  @brief 根据本地groupIds 更新数据
 *
 *  @param groups         groupInfo 对象
 *  @param completedBlock 网络返回解析后数据
 */
- (void)updateWithGroups:(NSArray<HoustonGroupInfo *> *)groups completed:(HoustonUpdaterCompletedBlock)completedBlock;

/**
 * @author gairui
 * 心跳接口
 *
 */
- (void)updateVersionWithCompleted:(void (^)(NSString *version, NSNumber *period, NSDictionary *data, NSError *error))compeletion;
@end
