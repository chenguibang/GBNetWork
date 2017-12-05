//
//  APiSessionManager.h
//  YTApp
//
//  Created by chenguibang on 2017/8/1.
//  Copyright © 2017年 chenguibang. All rights reserved.
//

#import <AFNetworking/AFNetworking.h>
#import "ApiRequest.h"
#import "ApiResponse.h"

#define TOKEN_CHANGE @"TOKEN_CHANGE"

@interface APiSessionManager : AFHTTPSessionManager

+ (instancetype)shared;
- (NSURLSessionDataTask *)API_GET:(ApiRequest *)request progress:(void (^)(NSProgress * progress))downloadProgress success:(void (^)(ApiResponse *response))success failure:(void (^)(NSURLSessionDataTask * task, NSError * error))failure;


@end
