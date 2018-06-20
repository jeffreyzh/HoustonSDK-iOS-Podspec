//
//  HoustonInternal.h
//  Pods
//
//  Created by 昆卡 on 16/8/24.
//
//

#import <Foundation/Foundation.h>
#import "HoustonRequestProtocol.h"

typedef void(^HoustonInternalObserverCallback)(NSString *groupName, NSString *key, id newValue);

@interface HoustonInternalObserver : NSObject

@property(nonatomic, copy, readonly) NSString *key;
@property(nonatomic, copy, readonly) NSString *group;

@end

@interface HoustonInternal : NSObject

/**
 *  启动配置中心
 */
+ (void)start;

/**
 *  启动配置中心
 */
+ (void)startWithRequestAdapter:(id <HoustonRequestProtocol>)requestAdapter;

/**
 *  获取某个 Group 下某个 Key 的值。先从内存中取，如果取不到，从磁盘取。
 *
 *  @param key       houston 中配置的 key
 *  @param groupName houston 中配置的 group 名
 *
 *  @return 要取的值，不存在则为 nil
 */
+ (nullable id)valueForKey:(NSString * __nonnull)key inGroup:(NSString *__nonnull)groupName;


/**
 *  为指定 group 下的某个 key 添加观察者，当 key 发生变化时触发回调。实际实现时，只要 group 发生变化，该 group 下所有的 key 的观察者都会被通知到。
 *
 *  @param key       houston 中配置的 key
 *  @param groupName houston 中配置的 group 名
 *  @param callback  回调
 */
+ (HoustonInternalObserver *)addObserverForKey:(NSString *__nonnull)key inGroup:(NSString *__nonnull)groupName withCallback:(HoustonInternalObserverCallback)callback;

/**
 *  移除观察者
 *
 *  @param HoustonInternalObserver 通过 addObserverForKey:inGroup:withCallback: 获取到的观察者对象
 */
+ (void)removeObserver:(HoustonInternalObserver *)houstonInternalObserver;

/**
 *  本地配置中心版本号
 *
 *  @return
 */
+ (NSString *)houstonVersion;

/**
 *  更新至某个版本，如果传入版本号与本地相同，则不触发更新。如果传入的版本号为 nil，那么不会比较版本号
 *
 *  @param version
 */
+ (void)updateToVersion:(NSString * __nullable)version;

/**
 * 调用这个方法后，向 Houston 服务发送请求时，将不会带上 group 版本信息，也就是让服务端那边再算一遍
 * 可以结合 `updateToVersion:nil` 一起使用
 */
+ (void)setNeedsReload;

/**
 * 调用这个方法后，向 Houston 服务发送请求时，将不会带上 group 版本信息，也就是让服务端那边再算一遍
 * @param version true:直接发起一次配置更新; false:等待心跳触发更新
 */
+ (void)releadToUpdate:(BOOL)immediateUpdate;
@end

