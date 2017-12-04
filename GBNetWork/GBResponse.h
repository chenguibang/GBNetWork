//
//  GBResponse.h
//  GBNetWork
//
//  Created by yh on 2017/12/4.
//  Copyright © 2017年 chengb. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GBRequest.h"
@protocol GBResponseHandle

- (void)progress:(void (^)(NSProgress * progress))downloadProgress success:(void (^)(id<GBResponseHandle> response))success failure:(void (^)(NSURLSessionDataTask * task, NSError * error))failure;

@end
@interface GBResponse : NSObject<GBResponseHandle>
@property (nonatomic, strong) NSData *originData;
@property (nonatomic, assign) NSData *object;
@property (nonatomic, strong) GBRequest *requst;
@end
