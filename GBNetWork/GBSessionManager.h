//
//  GBSessionManager.h
//  YTApp
//
//  Created by chenguibang on 2017/8/1.
//  Copyright © 2017年 chenguibang. All rights reserved.
//

#import <AFNetworking/AFNetworking.h>
#import "ApiRequest.h"
#import "ApiResponse.h"
#import "GBRequest.h"
#import "GBResponse.h"
@interface GBSessionManager : AFHTTPSessionManager

+ (instancetype)shared;

- (NSURLSessionDataTask *)API_GET:(ApiRequest *)request progress:(void (^)(NSProgress * progress))downloadProgress success:(void (^)(ApiResponse *response))success failure:(void (^)(NSURLSessionDataTask * task, NSError * error))failure;



- (NSURLSessionDataTask *)GB_GET:(GBRequest *)request progress:(void (^)(NSProgress * progress))downloadProgress success:(void (^)(id<GBResponseHandle> response))success failure:(void (^)(NSURLSessionDataTask * task, NSError * error))failure;


@end
