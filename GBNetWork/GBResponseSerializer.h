//
//  GBResponseSerializer.h
//  GBNetWork
//
//  Created by yh on 2017/12/4.
//  Copyright © 2017年 chengb. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol GBResponseSerialization

- (id)responseObject;

@end

@interface GBResponseSerializer : NSObject<GBResponseSerialization>

+ (instancetype)serializer;
@end
