//
//  GBRequestSerializer.h
//  GBNetWork
//
//  Created by yh on 2017/12/4.
//  Copyright © 2017年 chengb. All rights reserved.
//

#import <Foundation/Foundation.h>
@protocol GBRequestSerialization

@end

@interface GBRequestSerializer : NSObject<GBRequestSerialization>
+ (instancetype)serializer;
@end
