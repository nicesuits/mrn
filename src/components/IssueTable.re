[%bs.raw {|require('./IssueTable.css')|}];

let component = ReasonReact.statelessComponent("IssueTable");

let make = (~issues, _children) => {
  ...component,
  render: _self => {
    <table className="bordered-table">
      <thead>
        <tr>
          <th> {ReasonReact.string("Id")} </th>
          <th> {ReasonReact.string("Status")} </th>
          <th> {ReasonReact.string("Owner")} </th>
          <th> {ReasonReact.string("Created On")} </th>
          <th> {ReasonReact.string("Effort")} </th>
          <th> {ReasonReact.string("Completed On")} </th>
          <th> {ReasonReact.string("Title")} </th>
        </tr>
      </thead>
      <tbody>
        {ReasonReact.array(
           Array.of_list(
             List.map(
               (issue: IssueType.issue) =>
                 <IssueRow key={string_of_int(issue.id)} issue />,
               issues,
             ),
           ),
         )}
      </tbody>
    </table>;
  },
};