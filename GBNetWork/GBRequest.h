//
//  GBRequest.h
//  GBNetWork
//
//  Created by yh on 2017/12/4.
//  Copyright © 2017年 chengb. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GBRequestSerializer.h"
#import "GBResponseSerializer.h"
@protocol GBRequestProtocol

@end

@interface GBRequest : NSObject<GBRequestProtocol>
@property (nonatomic, strong) NSURLSessionDataTask *task;
@property (nonatomic, copy) NSString *serverUrl;
@property (nonatomic, copy) NSString *apiInterface;
@property (nonatomic, strong) NSDictionary *paths; //restful 风格参数
@property (nonatomic, assign) NSTimeInterval *timeout;
@property (nonatomic, assign) BOOL encrypt;
@property (nonatomic, strong) NSObject* paramters;
@property (nonatomic, assign) BOOL logParamter;
@property (nonatomic, assign) BOOL logRespone;
@property (nonatomic, assign) BOOL showMsg;
@property (nonatomic ,strong) NSMutableDictionary *headers;
@property (nonatomic, assign) id<GBRequestSerialization> requestSerializer;
@property (nonatomic, assign) id<GBResponseSerialization> responseSerializer;




@end
