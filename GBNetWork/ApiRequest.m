//
//  ApiBaseRequest.m
//  YTApp
//
//  Created by chenguibang on 2017/8/1.
//  Copyright © 2017年 chenguibang. All rights reserved.
//

#import "ApiRequest.h"



@implementation ApiRequest



- (instancetype)init
{
    self = [super init];
    if (self) {
//        self.serverUrl = @"http://ytapi.mhunsha.com";
        self.serverUrl = @"http://192.168.31.140:8989";
        self.showMsg = YES;
    }
    return self;
}




+ (instancetype)shared{
    
    static dispatch_once_t onceToken;
    static ApiRequest *shareInstance;
    dispatch_once(&onceToken, ^{
        shareInstance = [[ApiRequest alloc]init];
    });
    return shareInstance;
}

+ (instancetype)requestWith:(id)paramters{
    ApiRequest *request = [[ApiRequest alloc]init];
    request.paramters = paramters;
    return request;
}

+ (instancetype)requestWith:(id)paramters resposeClass:(Class)resposeClass{
    ApiRequest *request = [ApiRequest requestWith:paramters];
    return request;
}




- (NSMutableDictionary *)headers{
    if (!_headers) {
        _headers = [[NSMutableDictionary alloc]init];
    }
    return _headers;
}


- (void)ecrypt{
    
}

-(void)decrypt{
    
}


@end
