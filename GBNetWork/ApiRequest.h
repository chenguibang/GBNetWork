//
//  ApiBaseRequest.h
//  YTApp
//
//  Created by chenguibang on 2017/8/1.
//  Copyright © 2017年 chenguibang. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ApiRequest : NSObject
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

+ (instancetype) requestWith:(id)paramters;

+ (instancetype) requestWith:(id)paramters resposeClass:(Class)resposeClass;



+ (instancetype) shared;


/**
 参数加密
 */
- (void)ecrypt;

/**
 参数解密
 */
- (void)decrypt;



@end
