//
//  RootViewController.h
//  Couchbase Mobile
//
//  Created by Jan Lehnardt on 27/11/2010.
//  Copyright 2011 Couchbase, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may not
// use this file except in compliance with the License. You may obtain a copy of
// the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
// License for the specific language governing permissions and limitations under
// the License.
//

#import <UIKit/UIKit.h>
#import <Syncpoint/CouchUITableSource.h>
@class CouchDatabase, CouchPersistentReplication, Syncpoint;


@interface RootViewController : UIViewController <CouchUITableDelegate, UITextFieldDelegate>
{
    CouchDatabase *database;
    NSURL* remoteSyncURL;
    CouchPersistentReplication* _pull;
    CouchPersistentReplication* _push;
    BOOL _viewDidLoad;
    
    UITableView *tableView;
    IBOutlet UIProgressView *progress;
    BOOL showingSyncButton;
    IBOutlet UITextField *addItemTextField;
    IBOutlet UIImageView *addItemBackground;
}

@property(nonatomic, strong) IBOutlet UITableView *tableView;
@property(nonatomic, strong) IBOutlet CouchUITableSource* dataSource;

-(void)useDatabase:(CouchDatabase*)theDatabase;

- (IBAction)configureSync:(id)sender;
- (IBAction) deleteCheckedItems:(id)sender;

@end
