//
//  HoustonObject.h
//  Pods
//
//  Created by 昆卡 on 16/8/24.
//
//

#import <Foundation/Foundation.h>
#import "Houston.h"


/**
 *  对外暴露的 Houston 对象，业务方取值、加监听的所有操作都通过这个对象来完成
 */
@interface HoustonObject<__covariant T> : NSObject

/**
 *  key
 */
@property(nonatomic, copy, readonly) NSString *key;


/**
 *  group
 */
@property(nonatomic, copy, readonly) NSString *group;


/**
 *  当前值，在 HoustonObject 的生命周期内，该值永远是最新的
 */
@property(nonatomic, strong, readonly) T value;

/**
 *  创建 HoustonObject 对象
 *
 *  @param key          对应的 Key
 *  @param group        对应的 Group
 *  @param class        value 的类型，内部会使用 MGJEntity 来转换
 *  @param defaultValue 默认值，类型必须与传入的 class 一致
 *  @param block        回调
 *
 *  @return HoustonObject 对象
 */
- (instancetype)initWithKey:(NSString *__nonnull)key inGroup:(NSString *__nonnull)group withValueClass:(Class __nonnull)class defaultValue:(T __nullable)defaultValue observer:(void (^)(NSString *groupName, NSString *key, T oldValue, T newValue))block;
@end
