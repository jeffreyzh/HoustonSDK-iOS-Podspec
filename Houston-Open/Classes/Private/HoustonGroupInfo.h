//
//  HoustonGroupInfo.h
//  Pods
//
//  Created by 昆卡 on 16/8/27.
//
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, HoustonGroupActionType) {
    HoustonGroupActionTypeUnknown = -1,    
    HoustonGroupActionTypeModify = 0,       /// 修改操作
    HoustonGroupActionTypeDelete = 1,  /// 删除操作
    HoustonGroupActionTypeMerge = 2  /// 差量更新操作
};

/**
 *  @author kongkong
 *
 *  @brief 网络返回，action 操作取值
 */
FOUNDATION_EXPORT NSString *const HoustonGroupActionTypeStringValueModify;// modify
FOUNDATION_EXPORT NSString *const HoustonGroupActionTypeStringValueDelete;// delete
FOUNDATION_EXPORT NSString *const HoustonGroupKeyGroup;// group
FOUNDATION_EXPORT NSString *const HoustonGroupKeyVersion;
FOUNDATION_EXPORT NSString *const HoustonGroupKeyData;
FOUNDATION_EXPORT NSString *const HoustonGroupKeyAction;
FOUNDATION_EXPORT NSString *const HoustonGroupKeyDeleteData;

@interface HoustonGroupInfo : NSObject
@property(nonatomic, copy, readonly) NSString *name;
@property(nonatomic, copy, readonly) NSString *version;
@property(nonatomic, strong, readonly) NSDictionary *data;
@property(nonatomic, assign, readonly) HoustonGroupActionType action;
@property(nonatomic, strong,readonly) NSDictionary *delData;

/**
 *  @author kongkong
 *
 *  @brief 返回分组数据
 *
 *  @param value 存储本地数据或者网络数据
 *
 *  @return 分组数据对象
 */
+ (nullable instancetype)groupInfoWithDictionary:(NSDictionary *)dictionary;

/**
 *  @author kongkong
 *
 *  @brief 反序列化为 dictionary
 *
 *  @return 数据的 dictionary 表现
 */
- (NSDictionary *)dictionaryInfo;
@end
