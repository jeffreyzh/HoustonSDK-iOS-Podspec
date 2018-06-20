//
//  HoustonUpdaterProtocol.h
//  Pods
//
//  Created by 昆卡 on 2016/9/20.
//
//

#import <Foundation/Foundation.h>

@protocol HoustonRequestProtocol <NSObject>

@required
- (void)requestWithApi:(NSString*)api
               version:(NSString*)version
            parameters:(NSDictionary *)parameters
           compeletion:(void (^)(NSDictionary *responseData, NSError *error))compeletion;
@end
