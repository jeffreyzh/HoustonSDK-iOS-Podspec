//
//  HoustonStore.h
//  Pods
//
//  Created by 昆卡 on 16/8/27.
//
//

#import <Foundation/Foundation.h>
#import "HoustonGroupInfo.h"


@interface HoustonStore : NSObject

/**
 *  是否需要初始化
 */
@property (atomic, assign, readonly) BOOL isReady;

/**
 *  初始化 HoustonStore 实例
 *
 *  @param filePath 文件路径
 *
 *  @param completionBlock 从本地加载数据完成后的回调
 *  @return
 */
- (instancetype)initWithFilePath:(NSString*)filePath loadDiskDataCompleted:(void (^)())completionBlock;

/**
 *  获取指定 group 先从内存取，再从磁盘取
 *
 *  @param key       key
 *  @param groupName group
 *
 *  @return
 */
- (nullable id)groupForName:(NSString * __nonnull)groupName;

/**
 *  获取指定 group 下某个 Key 的值。先从内存取，再从磁盘取
 *
 *  @param key       key
 *  @param groupName group
 *
 *  @return
 */
- (nullable id)valueForKey:(NSString * __nonnull)key inGroup:(NSString * __nonnull)groupName;

/**
 *  从内存中获取指定 group 下某个 Key 的值
 *
 *  @param key       key
 *  @param groupName group
 *
 *  @return
 */
- (nullable id)valueFromMemoryForKey:(NSString * __nonnull)key inGroup:(NSString * __nonnull)groupName;

/**
 *  从硬盘中获取指定 group 下某个 Key 的值
 *
 *  @param key       key
 *  @param groupName group
 *
 *  @return
 */
- (nullable id)valueFromDiskForKey:(NSString * __nonnull)key inGroup:(NSString * __nonnull)groupName;


/**
 *  保存 group 信息
 *
 *  @param groupInfo group 信息
 */
- (void)saveGroup:(HoustonGroupInfo * __nonnull)groupInfo;

/**
 *  删除某个 group
 *
 *  @param groupName group 名字
 */
- (void)deleteGroupWithName:(NSString * __nonnull)groupName;

/**
 *  获取当前所有的 Group 和版本信息
 *
 *  @return 
 */
- (NSArray<HoustonGroupInfo *> *)groupAndVersions;
@end
