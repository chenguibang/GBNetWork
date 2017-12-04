//
//  ApiBaseResponse.h
//  YTApp
//
//  Created by chenguibang on 2017/8/1.
//  Copyright © 2017年 chenguibang. All rights reserved.
//

#import <Foundation/Foundation.h>
@interface ApiResponse : NSObject
@property (nonatomic ,strong) NSURLSessionDataTask *task;
@property (nonatomic ,strong) id data;
@end
