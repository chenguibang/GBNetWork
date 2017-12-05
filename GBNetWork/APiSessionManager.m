//
//  APiSessionManager.m
//  YTApp
//
//  Created by chenguibang on 2017/8/1.
//  Copyright © 2017年 chenguibang. All rights reserved.
//

#import "APiSessionManager.h"
#import <AFNetworking/AFNetworkActivityIndicatorManager.h>
#import <MJExtension/MJExtension.h>
#import <SVProgressHUD/SVProgressHUD.h>
@implementation APiSessionManager


+ (instancetype)shared{
    APiSessionManager *manager = [APiSessionManager manager];
    manager.responseSerializer = [AFJSONResponseSerializer serializer];
    manager.requestSerializer=[AFJSONRequestSerializer serializer];
    return manager;
}


- (NSURLSessionDataTask *)API_GET:(ApiRequest *)request progress:(void (^)(NSProgress * progress))downloadProgress success:(void (^)(ApiResponse *response))success failure:(void (^)(NSURLSessionDataTask * task, NSError * error))failure{
    
    if(request.token){
        [self.requestSerializer setValue:request.token ? request.token : @"" forHTTPHeaderField:@"token"];
    }
    [AFNetworkActivityIndicatorManager sharedManager].enabled = YES;
    [AFNetworkActivityIndicatorManager sharedManager].completionDelay = 0.3;
    if (request.logParamter) {
        NSLog(@"\n----------------------\n%@\n----------------------\n",[request.paramters mj_JSONObject]);
    }
    // 3. 参数处理
    NSString *url = [NSString stringWithFormat:@"%@%@",request.serverUrl,request.apiInterface];
    NSURLSessionDataTask *task = [self GET:url parameters:[request.paramters mj_JSONObject] progress:^(NSProgress * _Nonnull downloadProgress) {
        
    } success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
        if (request.logRespone) {
            NSLog(@"\n----------------------\n%@\n----------------------\n",[responseObject mj_JSONObject]);
        }
        if (request.showMsg) {
            NSString *tintMsg = [responseObject mj_keyValues][@"msg"];
            [SVProgressHUD showInfoWithStatus:tintMsg];
            
        }
        ApiResponse *respone = [[ApiResponse alloc]init];
        respone.task = task;
        respone.data = [responseObject mj_JSONObject];
        
        if (success) {
            success(respone);
        }
    } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
        if (failure) {
            failure(task,error);
        }
    }];
    request.task = task;
    return task;
    
}

@end
